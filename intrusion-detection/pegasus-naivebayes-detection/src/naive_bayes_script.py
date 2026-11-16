#!/usr/bin/env python3

"""
Detecção do Spyware Pegasus e Anomalias de Rede via Categorical Naive Bayes.
Aplicação prática de Machine Learning focado em Cibersegurança e Análise de Telemetria.
"""

import argparse
import os
import sys
from typing import Tuple

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import seaborn as sns
from sklearn.metrics import (
    accuracy_score,
    classification_report,
    confusion_matrix,
    f1_score,
    precision_score,
    recall_score,
)
from sklearn.model_selection import train_test_split
from sklearn.naive_bayes import CategoricalNB
from sklearn.preprocessing import OrdinalEncoder


def load_and_preprocess_data(filepath: str) -> Tuple[pd.DataFrame, pd.Series]:
    """Carrega o dataset, realiza imputação de nulos, discretização e codificação categórica.

    Args:
        filepath (str): Caminho para o arquivo CSV de telemetria.

    Returns:
        Tuple[pd.DataFrame, pd.Series]: Matriz de features X tratadas e vetor target y.
    """
    if not os.path.exists(filepath):
        raise FileNotFoundError(f"Arquivo de dados não encontrado em: {filepath}")

    df = pd.read_csv(filepath)

    # 1. Definição do Alvo Binário (1 = Malicioso / IoC presente, 0 = Legítimo)
    df["target_malicious"] = df["ioc"].notna().astype(int)

    # 2. Tratamento de nulos na telemetria
    df["anomaly_detected"] = df["anomaly_detected"].fillna("None")

    # 3. Discretização de variável contínua (data_volume -> 4 quartis categóricos)
    df["volume_bin"] = pd.qcut(
        df["data_volume"], q=4, labels=["Baixo", "Médio-Baixo", "Médio-Alto", "Alto"]
    )

    # 4. Atributos selecionados para a variante CategoricalNB
    feature_cols = [
        "device_type",
        "os_version",
        "app_usage_pattern",
        "protocol",
        "log_type",
        "event",
        "process",
        "anomaly_detected",
        "volume_bin",
    ]

    # 5. Encoding Ordinal de variáveis texto para inteiros
    encoder = OrdinalEncoder(handle_unknown="use_encoded_value", unknown_value=-1)
    X_encoded = pd.DataFrame(
        encoder.fit_transform(df[feature_cols]), columns=feature_cols
    )
    y = df["target_malicious"]

    return X_encoded, y


def train_categorical_naive_bayes(
    X_train: pd.DataFrame, y_train: pd.Series, alpha: float = 1.0
) -> CategoricalNB:
    """Instancia e treina o modelo Categorical Naive Bayes com Suavização de Laplace.

    Args:
        X_train (pd.DataFrame): Dados de treinamento.
        y_train (pd.Series): Rótulos de treinamento.
        alpha (float): Parâmetro de suavização de Laplace (padrão=1.0).

    Returns:
        CategoricalNB: Modelo treinado.
    """
    model = CategoricalNB(alpha=alpha)
    model.fit(X_train, y_train)
    return model


def evaluate_model_performance(
    model: CategoricalNB, X_test: pd.DataFrame, y_test: pd.Series
) -> Tuple[np.ndarray, dict]:
    """Realiza predições e calcula as métricas de desempenho.

    Args:
        model (CategoricalNB): Modelo treinado.
        X_test (pd.DataFrame): Dados de teste.
        y_test (pd.Series): Rótulos de teste reais.

    Returns:
        Tuple[np.ndarray, dict]: Matriz de confusão e dicionário com as métricas.
    """
    y_pred = model.predict(X_test)

    acc = accuracy_score(y_test, y_pred)
    prec = precision_score(y_test, y_pred, zero_division=0)
    rec = recall_score(y_test, y_pred, zero_division=0)
    f1 = f1_score(y_test, y_pred, zero_division=0)
    cm = confusion_matrix(y_test, y_pred)

    metrics = {
        "accuracy": acc,
        "precision": prec,
        "recall": rec,
        "f1_score": f1,
        "classification_report": classification_report(
            y_test, y_pred, target_names=["Legítimo", "Malicioso"]
        ),
    }

    return cm, metrics


def plot_confusion_matrix_heatmap(
    cm: np.ndarray, save_path: str = "confusion_matrix.png"
) -> None:
    """Gera e salva o gráfico Heatmap da Matriz de Confusão.

    Args:
        cm (np.ndarray): Matriz de confusão.
        save_path (str): Caminho para salvar a imagem.
    """
    plt.figure(figsize=(7, 5))
    sns.heatmap(
        cm,
        annot=True,
        fmt="d",
        cmap="Blues",
        xticklabels=["Previsto Legítimo", "Previsto Malicioso"],
        yticklabels=["Real Legítimo", "Real Malicioso"],
    )
    plt.title("Matriz de Confusão - Categorical Naive Bayes", fontsize=12)
    plt.xlabel("Classe Predita", fontsize=10)
    plt.ylabel("Classe Real", fontsize=10)
    plt.tight_layout()
    plt.savefig(save_path, dpi=300)
    print(f"[+] Gráfico da Matriz de Confusão salvo em: {save_path}")
    plt.close()


def main():
    parser = argparse.ArgumentParser(
        description="Treinamento do Categorical Naive Bayes para detecção do Pegasus."
    )
    parser.add_argument(
        "--data",
        type=str,
        default="synthetic_pegasus_dataset.csv",
        help="Caminho para o arquivo CSV contendo os dados de telemetria.",
    )
    args = parser.parse_args()

    print("=== INICIANDO PIPELINE DE DETECÇÃO DE PEGASUS VIA NAIVE BAYES ===")

    try:
        # Carregamento e Pré-processamento
        X, y = load_and_preprocess_data(args.data)
        print(f"[+] Dados carregados com sucesso. Amostras totais: {len(X)}")

        # Divisão Treino (70%) e Teste (30%) com Amostragem Estratificada
        X_train, X_test, y_train, y_test = train_test_split(
            X, y, test_size=0.30, random_state=42, stratify=y
        )
        print(
            f"[+] Amostras de Treino: {len(X_train)} | Amostras de Teste: {len(X_test)}"
        )

        # Treinamento
        model = train_categorical_naive_bayes(X_train, y_train, alpha=1.0)
        print("[+] Modelo CategoricalNB treinado (Suavização de Laplace alpha=1.0).")

        # Avaliação
        cm, metrics = evaluate_model_performance(model, X_test, y_test)

        # Exibição dos Resultados no Terminal
        print("\n" + "=" * 50)
        print("         RESULTADOS DE DESEMPENHO DO MODELO")
        print("=" * 50)
        print(f"Acurácia Geral:   {metrics['accuracy']*100:.2f}%")
        print(f"Precisão:         {metrics['precision']*100:.2f}%")
        print(
            f"Recall (Captura): {metrics['recall']*100:.2f}%  <-- Métrica Chave em SOC"
        )
        print(f"F1-Score:         {metrics['f1_score']*100:.2f}%")
        print("=" * 50)

        print("\nMatriz de Confusão (Valores Absolutos):")
        print(f"TN: {cm[0][0]} | FP: {cm[0][1]}")
        print(f"FN: {cm[1][0]} | TP: {cm[1][1]}")

        print("\nRelatório de Classificação Detalhado:")
        print(metrics["classification_report"])

        # Geração do Gráfico
        plot_confusion_matrix_heatmap(cm)

    except Exception as e:
        print(f"[-] Erro na execução do pipeline: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()