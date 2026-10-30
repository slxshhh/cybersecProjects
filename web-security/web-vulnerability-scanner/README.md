# 🌐 Web Vulnerability Scanner

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![libcurl](https://img.shields.io/badge/libcurl-073551?style=for-the-badge&logo=curl&logoColor=white)
![Requests](https://img.shields.io/badge/Requests-2CA5E0?style=for-the-badge&logo=python&logoColor=white)
![Regex](https://img.shields.io/badge/Regex-4B0082?style=for-the-badge&logo=regex&logoColor=white)

## 📝 Descrição do Projeto

O **Web Vulnerability Scanner** é uma ferramenta experimental desenvolvida para estudar os fundamentos de testes automatizados de segurança em aplicações web.

O projeto possui duas implementações, uma em C e outra em Python, ambas utilizando um mecanismo de detecção baseado em regras.

O funcionamento consiste na leitura de um arquivo `rules.csv`, contendo métodos HTTP, nomes de testes, payloads e expressões regulares. A ferramenta executa as requisições HTTP, analisa as respostas recebidas e verifica possíveis correspondências com os padrões definidos nas regras.

Quando uma correspondência é identificada, o scanner registra as informações da detecção em um arquivo `report.txt`, permitindo consultar os resultados posteriormente.

Durante o desenvolvimento, foi utilizado o **HTTPBin** como ambiente de testes para validar o funcionamento das requisições, aplicação de payloads, análise de respostas e geração de relatórios.

## 🚀 Implementações

### 🔹 Versão C

Desenvolvida utilizando `libcurl` para comunicação HTTP e `regex.h` para análise das respostas.

**Tecnologias e recursos:**
- Linguagem C
- libcurl
- regex.h
- Manipulação de arquivos CSV
- Alocação dinâmica de memória
- Requisições GET e POST
- Geração de relatórios

### 🔹 Versão Python

Reimplementação da ferramenta utilizando bibliotecas Python para simplificar o processamento das regras e das respostas HTTP.

**Tecnologias e recursos:**
- Python
- Requests
- Regex (`re`)
- CSV (`csv`)
- Manipulação de arquivos
- Requisições GET e POST
- Geração de relatórios

## ⚙️ Funcionamento

O scanner segue um fluxo de execução baseado nas seguintes etapas:

1. **Leitura das regras:** carrega as informações do arquivo `rules.csv`.
2. **Identificação do método:** verifica se a regra utiliza GET ou POST.
3. **Envio do payload:** realiza a requisição HTTP utilizando o payload definido.
4. **Análise da resposta:** aplica a expressão regular correspondente à regra.
5. **Identificação:** verifica se existe correspondência entre a resposta e o padrão esperado.
6. **Relatório:** registra as detecções encontradas em `report.txt`.

## 📄 Estrutura das Regras

O arquivo `rules.csv` utiliza quatro campos:

| Campo | Descrição |
|---|---|
| `method` | Método HTTP utilizado (GET ou POST). |
| `name` | Nome ou identificação da regra. |
| `payload` | Conteúdo enviado na requisição. |
| `regex` | Expressão regular utilizada na análise da resposta. |

**Formato:**

```csv
method,nome,payload,regex
```

As regras são carregadas durante a execução e utilizadas para determinar quais verificações serão realizadas.

## 📊 Relatórios

Quando uma correspondência é encontrada, as informações são registradas automaticamente em `report.txt`.

O relatório contém informações como:

- Nome da regra identificada.
- Método HTTP utilizado.
- URL consultada (na versão C).
- Payload enviado.
- Expressão regular utilizada.

## 🔧 Como Executar

### Pré-requisitos

**Versão C:**
- GCC ou compilador C compatível.
- Biblioteca libcurl instalada.
- Arquivo `rules.csv`.

**Versão Python:**
- Python 3.
- Biblioteca `requests`.
- Arquivo `rules.csv`.

### Versão C

Entre no diretório da implementação:

```bash
cd c
```

Compile utilizando GCC e libcurl:

```bash
gcc scanner.c -o scanner $(pkg-config --cflags --libs libcurl)
```

Execute:

```bash
./scanner
```

### Versão Python

Entre no diretório:

```bash
cd python
```

Instale a dependência:

```bash
pip install requests
```

Execute:

```bash
python scanner.py
```

**Observação:** o arquivo `rules.csv` deve estar disponível no diretório de execução do programa. O arquivo `report.txt` será criado ou sobrescrito automaticamente a cada execução.

## 🛡️ Conceitos Praticados

- Web Security
- HTTP e HTTPS
- Requisições GET e POST
- Parsing de arquivos CSV
- Expressões regulares (Regex)
- Detecção baseada em assinaturas
- Automação de testes de segurança
- Processamento de respostas HTTP
- Manipulação de memória em C
- Desenvolvimento e refatoração entre linguagens

## 🔭 Próximas Evoluções

- Expansão do conjunto de regras de detecção.
- Implementação de novas verificações de segurança web.
- Aprimoramento do tratamento de respostas HTTP.
- Padronização do comportamento entre as versões C e Python.
- Melhorias na organização e apresentação dos relatórios.
- Estudos de vulnerabilidades baseados no OWASP Top 10.

## ⚠️ Aviso de Uso

Projeto desenvolvido para fins educacionais e experimentação em segurança de aplicações web.

As verificações devem ser realizadas exclusivamente em ambientes próprios, laboratórios ou aplicações para as quais exista autorização expressa.

Uma correspondência de Regex representa uma possível detecção, não necessariamente a confirmação de uma vulnerabilidade.

---

*Projeto desenvolvido como parte dos meus estudos práticos em Cibersegurança, com foco em Web Security, automação e análise de aplicações web.*
