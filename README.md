<img width="2048" height="768" alt="image" src="https://github.com/user-attachments/assets/9c095dfe-91bb-4d13-a556-b2190f07ef93" />

# 🛡️ Cybersecurity Projects

![Cybersecurity](https://img.shields.io/badge/Cybersecurity-000000?style=for-the-badge&logo=kalilinux&logoColor=white)
![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)

## 📝 Sobre o Repositório

Este repositório reúne projetos desenvolvidos durante meus estudos e prática na área de **Cibersegurança**, com foco em redes, criptografia, autenticação, análise de dados, automação, reconhecimento e segurança de aplicações web.

A proposta é manter uma coleção evolutiva de projetos práticos, documentando meu processo de aprendizado e explorando diferentes conceitos, ferramentas e técnicas utilizadas no contexto de **Cybersecurity**.

Os projetos são desenvolvidos principalmente em **C e Python**, utilizando diferentes abordagens conforme o objetivo de cada ferramenta.

---

## 📑 Índice

- [🚀 Projetos](#-projetos) 
  - [🔐 Criptografia e Segurança de Senhas](#-criptografia-e-segurança-de-senhas)
  - [🔑 Autenticação](#-autenticação)
  - [🌐 Redes e Reconhecimento](#-redes-e-reconhecimento)
  - [🕸️ Segurança Web](#️-segurança-web)
  - [🛡️ Detecção de Intrusão e Ameaças](#️-detecção-de-intrusão-e-ameaças)
- [🧰 Tecnologias](#-tecnologias)
- [📊 Áreas de Estudo](#-áreas-de-estudo)
- [🔧 Como executar](#-como-executar)
- [📚 Objetivo](#-objetivo)
- [⚠️ Aviso de uso](#️-aviso-de-uso)
- [📈 Status](#-status)

---

## 🚀 Projetos

### 🔐 Criptografia e Segurança de Senhas

Projetos voltados ao estudo de hashing, operações criptográficas, gerenciamento de credenciais e proteção de informações.

#### 🔨 Hash Cracker

**Linguagem:** C

Ferramenta desenvolvida para explorar o conceito de **quebra de hashes**, permitindo compreender na prática como ataques de força bruta e/ou dicionário podem ser utilizados contra funções de hash.

**Conceitos praticados:**
- Hashing
- Criptografia e funções de hash
- Brute Force
- Dictionary Attack
- Manipulação de arquivos
- Performance em C

## Como executar

### Pré-requisitos

- GCC
- OpenSSL
- Arquivo `wordlist.txt` na pasta do projeto.

### Linux (Kali/Debian/Ubuntu)

**1. Instale as dependências:**

```bash
sudo apt update
sudo apt install build-essential libssl-dev
```

**2. Compile o programa:**

```bash
gcc hash_cracker.c -o hash_cracker -lcrypto
```

**3. Execute:**

```bash
./hash_cracker
```

### Windows (MSYS2 UCRT64)

**1. Instale o GCC e o OpenSSL:**

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-openssl
```

**2. Compile o programa:**

```bash
gcc hash_cracker.c -o hash_cracker.exe -lcrypto
```

**3. Execute:**

```bash
./hash_cracker.exe
```

### Arquivos necessários

O arquivo `wordlist.txt` deve estar no diretório de execução do programa.

### Observações

- O projeto utiliza MD5 para calcular o hash das palavras presentes na wordlist.
- O hash-alvo está definido diretamente no código-fonte.
- O MD5 é utilizado exclusivamente para fins educacionais e demonstração de conceitos de identificação e comparação de hashes. Não é recomendado para aplicações criptográficas modernas.

📂 [Acessar projeto](./password-security/hash-cracker/)

---

#### 🔑 Pass Manager

**Linguagem:** C

Gerenciador de senhas desenvolvido em C para armazenar e organizar credenciais associadas a diferentes serviços. A ferramenta registra o nome do serviço, o usuário e a senha em um arquivo `.txt`, aplicando uma operação de **XOR para ofuscar as senhas armazenadas**.

O projeto explora conceitos fundamentais de manipulação de arquivos, operações bit a bit e gerenciamento de dados sensíveis.

**Conceitos praticados:**
- Operações bit a bit (Bitwise XOR)
- Ofuscação de senhas
- Manipulação de arquivos em C
- Leitura e escrita de dados
- Gerenciamento de credenciais
- Manipulação de strings
- Segurança de informações sensíveis

## Como executar

### Pré-requisitos

- GCC (GNU Compiler Collection).

### Linux (Kali/Debian/Ubuntu)

**1. Instale o GCC, caso ainda não esteja instalado:**

```bash
sudo apt update
sudo apt install build-essential
```

**2. Compile o programa:**

```bash
gcc pass_manager.c -o pass_manager
```

**3. Execute:**

```bash
./pass_manager
```

### Windows (MSYS2 UCRT64)

**1. Instale o GCC, caso ainda não esteja instalado:**

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

**2. Compile o programa:**

```bash
gcc pass_manager.c -o pass_manager.exe
```

**3. Execute:**

```bash
./pass_manager.exe
```

### Arquivos gerados

- `password_db.txt`: arquivo criado automaticamente para armazenar os serviços, usuários e senhas cadastrados.

### Observações

- O programa solicita o serviço, o nome de usuário e a senha.
- As credenciais são armazenadas em `password_db.txt`.
- As senhas passam por uma operação XOR utilizando uma chave fixa (`K`) antes de serem gravadas.
- **Atenção:** XOR com chave fixa é apenas uma forma de ofuscação, não uma criptografia segura. O projeto tem finalidade educacional e não deve ser utilizado para armazenar senhas reais.

📂 [Acessar projeto](./password-security/pass-manager/)

---

#### 🔏 Message Encryption & Decryption

**Linguagem:** C

Script desenvolvido em C para demonstrar o processo de criptografia e descriptografia de mensagens utilizando a operação **XOR (Exclusive OR)**. O programa recebe uma mensagem, aplica a operação XOR com uma chave definida, exibe o conteúdo criptografado e utiliza a mesma chave para recuperar a mensagem original.

O projeto explora conceitos fundamentais de criptografia simétrica, operações bit a bit e reversibilidade de dados.

**Conceitos praticados:**
- Criptografia simétrica
- Operações bit a bit (Bitwise XOR)
- Criptografia e descriptografia de mensagens
- Uso e reutilização de chaves
- Manipulação de strings em C
- Reversibilidade de operações
- Fundamentos de criptografia

## Como executar

### Pré-requisitos

- GCC (GNU Compiler Collection).
- Não são necessárias bibliotecas externas.

### Linux (Kali/Debian/Ubuntu)

**1. Instale o GCC, caso ainda não esteja instalado:**

```bash
sudo apt update
sudo apt install build-essential
```

**2. Compile o programa:**

```bash
gcc crypto.c -o crypto
```

**3. Execute:**

```bash
./crypto
```

### Windows (MSYS2 UCRT64)

**1. Instale o GCC, caso ainda não esteja instalado:**

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
```

**2. Compile o programa:**

```bash
gcc crypto.c -o crypto.exe
```

**3. Execute:**

```bash
./crypto.exe
```

### Funcionalidades

- Recebimento de uma mensagem pelo terminal.
- Definição de uma chave de um caractere.
- Aplicação da operação XOR para transformar a mensagem.
- Recuperação da mensagem original utilizando a mesma chave.

### Observações

- O projeto utiliza exclusivamente bibliotecas padrão do C.
- A operação XOR é reversível quando aplicada novamente com a mesma chave.
- A implementação utiliza um único caractere como chave.
- **Atenção:** essa implementação é didática e não oferece segurança criptográfica real. XOR com chave fixa ou curta não deve ser utilizado para proteger informações sensíveis.

📂 [Acessar projeto](./cryptography/message-encryption-c/)

---

#### 🔒 Fernet Encryption & Decryption

**Linguagem:** Python

Script desenvolvido em Python utilizando a biblioteca `cryptography` e o módulo `Fernet` para demonstrar o processo de criptografia e descriptografia de mensagens. O programa recebe uma mensagem, realiza sua criptografia com uma chave gerada, exibe o conteúdo criptografado e a chave utilizada e, em seguida, descriptografa os dados para recuperar a mensagem original.

O projeto explora conceitos de criptografia simétrica moderna, gerenciamento de chaves e proteção da integridade dos dados, permitindo comparar uma implementação baseada em XOR, desenvolvida anteriormente em C, com uma solução criptográfica mais robusta.

**Conceitos praticados:**
- Criptografia simétrica com Fernet
- Biblioteca `cryptography` do Python
- Geração e gerenciamento de chaves
- Criptografia e descriptografia de mensagens
- Integridade e autenticidade dos dados
- Codificação de dados criptografados
- Fundamentos de segurança da informação

## Como executar

### Pré-requisitos

- Python 3 instalado.
- Biblioteca `cryptography`.

### Linux (Kali/Debian/Ubuntu)

**1. Crie um ambiente virtual (opcional, mas recomendado):**

```bash
python3 -m venv venv
source venv/bin/activate
```

**2. Instale a dependência:**

```bash
pip install -r requirements.txt
```

**3. Execute o script:**

```bash
python3 crypto.py
```

### Windows

**1. Crie e ative um ambiente virtual (opcional, mas recomendado):**

```powershell
python -m venv venv
.\venv\Scripts\Activate.ps1
```

**2. Instale a dependência:**

```powershell
pip install -r requirements.txt
```

**3. Execute o script:**

```powershell
python crypto.py
```

### Dependências

O arquivo `requirements.txt` deve conter:

```text
cryptography
```

### Funcionalidades

- Geração automática de chave simétrica utilizando Fernet.
- Criptografia de mensagens.
- Descriptografia da mensagem utilizando a mesma chave.
- Exibição da chave gerada, do conteúdo criptografado e da mensagem original.

### Observações

- O projeto utiliza a biblioteca Cryptography e o algoritmo Fernet.
- Uma nova chave é gerada a cada execução.
- A chave permanece em memória durante a execução do programa.
- A demonstração trabalha com mensagens digitadas pelo usuário, não realiza criptografia de arquivos.
- A chave gerada é necessária para descriptografar os dados posteriormente. Se ela for perdida, não será possível recuperar a mensagem criptografada.

📂 [Acessar projeto](./cryptography/fernet-encryption-python/)

---

### 🔑 Autenticação

Projetos voltados ao estudo de autenticação, validação de credenciais e armazenamento de informações de usuários.

#### 🔐 Authentication System

**Linguagem:** Python

Sistema de autenticação desenvolvido em Python para simular o funcionamento de um mecanismo de cadastro e login de usuários. O módulo `auth_system` permite cadastrar usuários e armazenar suas senhas em formato hash utilizando **SHA-256**, salvando os registros em um arquivo `.json`. O módulo `login` verifica a existência do usuário cadastrado e valida as credenciais informadas para simular o processo de autenticação.

**Conceitos praticados:**
- Autenticação de usuários
- Hashing de senhas com SHA-256
- Manipulação de arquivos JSON
- Cadastro e validação de credenciais
- Comparação de hashes
- Estruturação de módulos em Python
- Fundamentos de segurança da informação

## Como executar

### Pré-requisitos

- Python 3 instalado.

### Linux (Kali/Debian/Ubuntu)

**1. Verifique a instalação do Python:**

```bash
python3 --version
```

**2. Execute o sistema de cadastro:**

```bash
python3 auth_system.py
```

**3. Execute o sistema de autenticação:**

```bash
python3 login.py
```

### Windows

**1. Verifique a instalação do Python:**

```powershell
python --version
```

**2. Execute o sistema de cadastro:**

```powershell
python auth_system.py
```

**3. Execute o sistema de autenticação:**

```powershell
python login.py
```

### Arquivos gerados

- `users.json`: arquivo criado pelo `auth_system.py`, contendo os nomes de usuários e seus respectivos hashes SHA-256.

### Fluxo de funcionamento

1. Execute `auth_system.py` para cadastrar um usuário.
2. Informe o nome de usuário e a senha desejada.
3. O sistema gera o hash SHA-256 da senha e salva as informações em `users.json`.
4. Execute `login.py` para realizar a autenticação.
5. Informe as credenciais cadastradas.
6. O sistema compara o hash da senha informada com o valor armazenado e retorna o resultado da autenticação.

### Observações

- Os dois scripts devem permanecer no mesmo diretório de `users.json`.
- O arquivo `users.json` é criado automaticamente durante o cadastro.
- O projeto utiliza SHA-256 para demonstrar o armazenamento e a comparação de hashes de senhas.
- **Atenção:** SHA-256 puro não é recomendado para armazenamento de senhas em aplicações reais. Sistemas de produção devem utilizar algoritmos específicos para senhas, como Argon2id, bcrypt ou scrypt.

📂 [Acessar projeto](./authentication/authentication-system/)

---

### 🌐 Redes e Reconhecimento

Ferramentas desenvolvidas para estudar comunicação entre dispositivos, reconhecimento de redes, processamento de resultados e automação.

#### 🔎 Port Scanner

**Linguagem:** Python

Scanner de portas desenvolvido para identificar **portas TCP abertas** em um determinado host. O projeto explora conceitos fundamentais de redes e reconhecimento utilizados em testes de segurança.

**Conceitos praticados:**
- TCP/IP
- Sockets
- Port Scanning
- Network Reconnaissance
- Tratamento de conexões
- Automação com Python

## Como executar

### Pré-requisitos

- Python 3 instalado.
- Não são necessárias bibliotecas externas.

### Linux (Kali/Debian/Ubuntu)

**1. Verifique a instalação do Python:**

```bash
python3 --version
```

**2. Execute o scanner:**

```bash
python3 port_scanner.py
```

### Windows

**1. Verifique a instalação do Python:**

```powershell
python --version
```

**2. Execute o scanner:**

```powershell
python port_scanner.py
```

### Configuração

O alvo e o intervalo de portas são definidos diretamente no código-fonte:

```python
scanner = PortScanner('127.0.0.1', 20, 100)
```

- `127.0.0.1`: endereço IP do alvo.
- `20`: porta inicial.
- `100`: porta final.

Para modificar a varredura, altere os valores passados ao construtor da classe `PortScanner`.

### Funcionalidades

- Varredura de portas TCP.
- Identificação de portas abertas por meio de conexões socket.
- Definição de timeout de conexão.
- Exibição do alvo, intervalo analisado e resultados da varredura.

### Observações

- O projeto utiliza exclusivamente bibliotecas nativas do Python.
- A varredura utiliza conexões TCP e timeout de 0,5 segundo.
- O alvo padrão é `127.0.0.1`, limitado às portas de 20 a 100.
- Utilize a ferramenta somente em sistemas e redes próprios ou para os quais você tenha autorização explícita.

📂 [Acessar projeto](./network/port-scanner/)

---

#### 📊 Scan Parser

**Linguagem:** Python

Ferramenta destinada ao **processamento e análise dos resultados de scans**, transformando informações brutas em dados mais estruturados e fáceis de interpretar.

O projeto tem como objetivo facilitar a análise de resultados provenientes de ferramentas de reconhecimento e scanners de rede.

**Conceitos praticados:**
- Parsing de dados
- Automação
- Manipulação de arquivos
- Expressões regulares
- Tratamento e organização de resultados

## Como executar

### Pré-requisitos

- Python 3 instalado.
- Não são necessárias bibliotecas externas.

### Linux (Kali/Debian/Ubuntu)

**1. Verifique a instalação do Python:**

```bash
python3 --version
```

**2. Execute o script:**

```bash
python3 scan_parser.py
```

### Windows

**1. Verifique a instalação do Python:**

```powershell
python --version
```

**2. Execute o script:**

```powershell
python scan_parser.py
```

### Configuração

Os endereços IP e suas respectivas portas estão definidos diretamente no dicionário `dic`, no código-fonte:

```python
dic = {
    "192.168.1.1": [22, 21, 443],
    "10.0.0.5": [443, 22],
    "172.16.0.100": [8080, 80, 443, 22, 21]
}
```

Para adicionar ou modificar os dados, altere os endereços IP e as listas de portas.

### Funcionalidades

- Armazenamento de endereços IP e portas em um dicionário.
- Percorrimento dos registros utilizando estruturas de repetição.
- Exibição dos endereços IP e suas respectivas portas no terminal.

### Observações

- O projeto utiliza exclusivamente recursos nativos do Python.
- Os dados são estáticos e definidos diretamente no código.
- O script não realiza varreduras de rede nem verifica vulnerabilidades. Ele apenas apresenta os dados fornecidos.

📂 [Acessar projeto](./network/scan-parser/)

---

### 🕸️ Segurança Web

Projetos relacionados à coleta automatizada de informações e análise de aplicações web, explorando conceitos de HTTP, reconhecimento e identificação de possíveis vulnerabilidades.

#### 🌐 Web Scraper

**Linguagem:** Python

Ferramenta desenvolvida para realizar **coleta automatizada de informações disponíveis em páginas web**, permitindo estudar técnicas de scraping e processamento de conteúdo.

**Conceitos praticados:**
- HTTP/HTTPS
- Web Scraping
- Requisições HTTP
- Parsing de HTML
- Automação
- Manipulação de dados

## Como executar

### Pré-requisitos

- Python 3 instalado.
- Bibliotecas `requests` e `beautifulsoup4`.

### Linux (Kali/Debian/Ubuntu)

**1. Crie e ative um ambiente virtual (opcional, mas recomendado):**

```bash
python3 -m venv venv
source venv/bin/activate
```

**2. Instale as dependências:**

```bash
pip install -r requirements.txt
```

**3. Execute o script:**

```bash
python3 web_scraper.py
```

### Windows

**1. Crie e ative um ambiente virtual (opcional, mas recomendado):**

```powershell
python -m venv venv
.\venv\Scripts\Activate.ps1
```

**2. Instale as dependências:**

```powershell
pip install -r requirements.txt
```

**3. Execute o script:**

```powershell
python web_scraper.py
```

### Dependências

O arquivo `requirements.txt` deve conter:

```text
requests
beautifulsoup4
```

### Funcionalidades

- Realização de requisições HTTP utilizando Requests.
- Análise do conteúdo HTML com BeautifulSoup.
- Extração do título da página.
- Identificação e exibição dos links encontrados no HTML.

### Observações

- O endereço utilizado atualmente é `https://quotes.toscrape.com/`.
- O script verifica se a requisição retornou o status HTTP 200 antes de processar o conteúdo.
- O projeto possui finalidade educacional, demonstrando conceitos básicos de Web Scraping.

📂 [Acessar projeto](./web-security/web-scraper/)

---

#### 🛡️ Web Vulnerability Scanner

<badge>Versões C e Python</badge>

Ferramenta experimental desenvolvida para explorar os fundamentos de **testes automatizados de segurança em aplicações web**.

O scanner utiliza um mecanismo de detecção baseado em regras armazenadas em um arquivo CSV. As ferramentas executam requisições HTTP, analisam as respostas recebidas por meio de expressões regulares e registram possíveis correspondências em um relatório `report.txt`.

O projeto possui duas implementações:

**Versão C**
- Linguagem C
- Biblioteca `libcurl`
- `regex.h`
- Requisições GET e POST
- Parsing de regras CSV
- Geração de relatórios

**Versão Python**
- Python
- Biblioteca `requests`
- Módulo `re`
- Módulo `csv`
- Requisições GET e POST
- Geração de relatórios

**Conceitos praticados:**
- Web Security
- HTTP/HTTPS
- Requisições HTTP
- Expressões regulares (Regex)
- Detecção baseada em assinaturas
- Automação de testes de segurança
- Parsing de arquivos CSV
- Análise de respostas HTTP

**Evolução do projeto:**
- Implementação inicial em C.
- Refatoração e reimplementação em Python.
- Expansão futura das regras e verificações de segurança.

**Documentação e execução:** consulte o README individual do projeto.

📂 [Documentação completa](./web-security/web-vulnerability-scanner/README.md)

---

### 🛡️ Detecção de Intrusão e Ameaças

#### 🚧 Intrusion Detection System (IDS)

**Status:** Planejado

Sistema de Detecção de Intrusão (IDS) que será desenvolvido para estudar o monitoramento de atividades, identificação de padrões suspeitos e geração de alertas de segurança.

**Conceitos planejados:**
- Monitoramento de rede
- Análise de tráfego e eventos
- Detecção de atividades suspeitas
- Logs e geração de alertas
- Network Security
- Blue Team

📂 [Acessar diretório do projeto](./intrusion-detection/)

---

#### 🕵️ Pegasus Telemetry Detection — Categorical Naive Bayes

**Linguagem:** Python

Projeto de pesquisa que utiliza o algoritmo **Categorical Naive Bayes**, da biblioteca Scikit-Learn, para classificar dados de telemetria de rede e identificar padrões associados a atividades maliciosas relacionadas ao spyware Pegasus.

A solução foi desenvolvida com foco em uma possível aplicação como filtro de primeira linha em um **Security Operations Center (SOC)**, priorizando a identificação de ameaças. Na avaliação realizada com uma base sintética, o modelo alcançou **93,78% de Recall** em 300 amostras de teste.

**Conceitos praticados:**
- Machine Learning aplicado à Cibersegurança
- Teorema de Bayes
- Categorical Naive Bayes
- Classificação supervisionada
- Análise de telemetria de rede
- Engenharia e pré-processamento de dados
- Discretização por quantis (`pd.qcut`)
- Codificação de atributos categóricos (`OrdinalEncoder`)
- Avaliação de modelos: Recall, Precisão, F1-Score e Acurácia
- Detecção de ameaças e contexto SOC

**Tecnologias utilizadas:**
- Python 3.10+
- Pandas e NumPy
- Scikit-Learn
- Matplotlib e Seaborn

**Documentação e execução:** consulte o README individual do projeto.

📂 [Documentação completa](intrusion-detection/pegasus-naivebayes-detection)

---

## 🧰 Tecnologias

Atualmente, os projetos utilizam principalmente:

| Tecnologia | Aplicação |
|---|---|
| C | Desenvolvimento de ferramentas de baixo nível e estudos de performance |
| Python | Automação, redes, processamento de dados e ferramentas de segurança |
| libcurl | Comunicação HTTP em C |
| Requests | Requisições HTTP em Python |
| Regex | Análise e identificação de padrões |
| CSV / JSON | Armazenamento e processamento de dados |
| Linux | Ambiente de desenvolvimento e estudos de segurança |
| Git/GitHub | Versionamento e documentação dos projetos |

---

## 📊 Áreas de Estudo

Os projetos deste repositório exploram diferentes áreas relacionadas à cibersegurança:

| Área | Conceitos |
|---|---|
| 🔐 Criptografia | Hashing, XOR, Fernet e criptografia simétrica |
| 🔑 Autenticação | Cadastro, validação e armazenamento de credenciais |
| 🌐 Redes | TCP/IP, sockets, portas e protocolos |
| 🔎 Reconhecimento | Port scanning e coleta de informações |
| 📊 Análise | Parsing, processamento e organização de dados |
| 🤖 Automação | Scripts e ferramentas de segurança |
| 🕸️ Web Security | HTTP, scraping e análise de aplicações web |
| 🛡️ Blue Team | Monitoramento, logs e detecção de intrusões |
| 🐧 Linux | Ambiente, ferramentas e fundamentos de segurança |

---

## 🔧 Como executar

Cada projeto possui seus próprios requisitos, dependências e procedimentos de execução.

Para executar uma ferramenta:

1. Clone o repositório:

   ```bash
   git clone https://github.com/gianlucca/cybersecProjects.git
   ```

2. Acesse o diretório do projeto desejado:

   ```bash
   cd cybersecProjects
   ```

3. Entre na pasta correspondente à ferramenta.

4. Consulte as instruções específicas de instalação e execução.

**Observação:** os projetos possuem diferentes dependências e configurações. As instruções detalhadas serão documentadas individualmente, conforme cada ferramenta for sendo organizada.

---

## 📚 Objetivo

Este repositório funciona como um **laboratório pessoal de cibersegurança**, onde novos projetos, experimentos e estudos serão adicionados continuamente.

O objetivo é transformar conceitos teóricos em implementações práticas, desenvolvendo conhecimento em:

- Network Security
- Cybersecurity
- Offensive Security
- Defensive Security
- Security Automation
- Scripting
- Network Reconnaissance
- Cryptography
- Linux Security
- Web Application Security

À medida que novos projetos forem desenvolvidos, eles serão adicionados a este repositório juntamente com sua documentação e tecnologias utilizadas.

---

## ⚠️ Aviso de Uso

As ferramentas presentes neste repositório foram desenvolvidas para **fins educacionais, de pesquisa e testes em ambientes autorizados**.

Não utilize estas ferramentas contra sistemas, redes ou aplicações sem a devida autorização.

Algumas implementações são experimentais e não devem ser consideradas soluções de segurança prontas para produção.

---

## 📈 Status

<badge color="success">Em desenvolvimento contínuo</badge>

Novos projetos, funcionalidades e melhorias serão adicionados ao longo do tempo.

---

*Repositório desenvolvido como parte da minha jornada de estudos e desenvolvimento prático em Cibersegurança.*
