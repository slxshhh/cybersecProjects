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
  - [🛡️ Detecção de Intrusão](#️-detecção-de-intrusão)
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

### 🛡️ Detecção de Intrusão

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
