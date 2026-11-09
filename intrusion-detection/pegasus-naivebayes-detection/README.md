# Detecção de Telemetria do Spyware Pegasus usando Categorical Naive Bayes

![Python](https://img.shields.io/badge/Python-3.10%2B-blue?style=for-the-badge&logo=python)
![Scikit-Learn](https://img.shields.io/badge/scikit--learn-F79A3E?style=for-the-badge&logo=scikit-learn&logoColor=white)
![Cybersecurity](https://img.shields.io/badge/Domain-Cybersecurity%20%2F%20SOC-red?style=for-the-badge)
![Recall Metric](https://img.shields.io/badge/Recall%20(Detection%20Rate)-93.78%25-brightgreen?style=for-the-badge)

## 📌 Visão Geral do Projeto

Este projeto desenvolve e avalia um classificador probabilístico de **Aprendizado de Máquina (Categorical Naive Bayes)** aplicado à cibersegurança e análise de telemetria de rede. O objetivo principal é atuar como um **filtro de primeira linha em Centros de Operações de Segurança (SOC)** para a detecção de intrusões e exfiltração de dados associadas a spywares avançados como o **Pegasus**.

Embora spywares sofisticados operem via vulnerabilidades *zero-click* e sejam praticamente invisíveis dentro do dispositivo infectado, a exfiltração de dados gera uma assinatura estatística identificável no tráfego de rede e nos logs do sistema.

---

## 📊 Métricas de Desempenho em Destaque

| Métrica | Valor Obtido | Significado Prático em SOC |
| :--- | :---: | :--- |
| **Recall (Sensibilidade)** | **93,78%** | **Taxa de Captura de Ameaças:** O modelo identificou e bloqueou 196 de 209 ataques reais. |
| **F1-Score** | **79,67%** | Equilíbrio harmônico geral considerando os desafios de amostragem. |
| **Precisão** | **69,26%** | Proporção de alarmes confirmados como maliciosos. |
| **Acurácia** | **66,67%** | Acurácia geral de classificação no conjunto de teste. |

### Matriz de Confusão ($N = 300$ amostras de teste)

```text
                       +-------------------------------+-------------------------------+
                       |      Previsto: LEGÍTIMO       |      Previsto: MALICIOSO      |
+----------------------+-------------------------------+-------------------------------+
| Realidade: LEGÍTIMO  | Verdadeiros Negativos (TN): 4 | Falsos Positivos (FP): 87     |
| Realidade: MALICIOSO | Falsos Negativos (FN): 13     | Verdadeiros Positivos (TP): 196|
+----------------------+-------------------------------+-------------------------------+
```

* **Priorização do Recall:** Em monitoramento defensivo, um **Falso Negativo ($FN = 13$)** representa uma invasão não detectada, enquanto um **Falso Positivo ($FP = 87$)** gera apenas a checagem por um analista. O modelo prioriza a minimização de $FN$.

---

## 🛠️ Pipeline de Dados e Arquitetura

1. **Limpeza e Imputação:** Dados de anomalias ausentes são tratados como classe neutra (`'None'`).
2. **Discretização por Quantis (`pd.qcut`):** A variável contínua `data_volume` (bytes transferidos) é convertida em 4 faixas categóricas (`Baixo`, `Médio-Baixo`, `Médio-Alto`, `Alto`).
3. **Codificação Categórica (`OrdinalEncoder`):** Mapeamento ordinal de atributos qualitativos como tipos de dispositivo, protocolos (HTTP, HTTPS, SSH, FTP), eventos e processos.
4. **Modelagem:** `CategoricalNB` com Suavização de Laplace ($\alpha = 1.0$) para contornar o problema de frequência zero.

---

## 📂 Estrutura do Repositório

```text
.
├── README.md                      # Apresentação do projeto e resultados
├── synthetic_pegasus_dataset.csv  # Base de dados de telemetria de rede
├── src/
│   └── train_and_evaluate.py      # Script em Python modularizado e executável
└── docs/
    ├── relatorio_tecnico.pdf      # Relatório acadêmico/técnico completo (ABNT)
    └── slides_apresentacao.pdf    # Slides da apresentação
```

---

## 🚀 Como Executar

### 1. Pré-requisitos
Certifique-se de ter o Python 3.10+ instalado juntamente com as bibliotecas necessárias:

```bash
pip install pandas numpy scikit-learn matplotlib seaborn
```

### 2. Execução do Script Refatorado
Rode o script diretamente via terminal:

```bash
python src/train_and_evaluate.py --data synthetic_pegasus_dataset.csv
```

---

## 🔬 Fundamentação Teórica Breve

O Teorema de Bayes calcula a probabilidade *a posteriori* de uma amostra ser maliciosa ($Y$) dadas as evidências observadas nas *features* ($X$):

$$P(Y \mid X_1, \dots, X_n) = \frac{P(Y) \prod_{i=1}^{n} P(X_i \mid Y)}{P(X_1, \dots, X_n)}$$

* **Hipótese de Independência Condicional:** O Naive Bayes assume independência entre variáveis como `process` e `protocol`. Embora essa suposição seja violada na cibersegurança real (ataques costumam correlacionar processos e protocolos), o algoritmo preserva a capacidade de ordenação das classes e entrega excelente velocidade de triagem em tempo real.