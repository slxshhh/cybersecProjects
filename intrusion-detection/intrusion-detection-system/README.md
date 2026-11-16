# 📡 Intrusion Detection System (IDS)

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![libpcap](https://img.shields.io/badge/libpcap-003366?style=for-the-badge&logo=wireshark&logoColor=white)
![Scapy](https://img.shields.io/badge/Scapy-2E8B57?style=for-the-badge&logo=python&logoColor=white)
![Network Security](https://img.shields.io/badge/Network_Security-8B0000?style=for-the-badge&logo=linux&logoColor=white)

## 📝 Descrição do Projeto

O **Intrusion Detection System (IDS)** é uma ferramenta experimental de monitoramento passivo de rede desenvolvida para estudar os fundamentos de **inspeção profunda de pacotes (DPI)** e detecção de anomalias em tempo real.

O projeto possui duas implementações — uma em C e outra em Python — que colocam a interface de rede em **Modo Promíscuo** para capturar o tráfego bruto, dissecar os cabeçalhos das camadas de Rede (IP), Transporte (TCP) e Aplicação (HTTP) e disparar alertas diante de comportamentos suspeitos.

Durante o desenvolvimento, foram utilizados ambientes controlados de laboratório (como **Nmap** para simulação de varreduras furtivas e **HTTPBin/cURL** para geração de tráfego web em texto claro) para validar a precisão da análise.

## 🚀 Implementações

### 🔹 Versão C

Desenvolvida em baixo nível utilizando `libpcap` para captura direta da placa de rede e estruturas nativas do kernel Linux (`<netinet/*>`) para dissecção byte a byte dos cabeçalhos.

**Tecnologias e recursos:**
- Linguagem C
- `libpcap` (Modo Promíscuo e Loop de Captura)
- Aritmética de ponteiros para salto de camadas (Ethernet, IP e TCP)
- Conversão de *Endianness* (`ntohs`) e IPs (`inet_ntoa`)
- Análise de *flags* TCP via operações *bitwise* (`& TH_SYN`)
- Inspeção de payload HTTP (`GET` e `POST`)

### 🔹 Versão Python

Reimplementação utilizando a biblioteca **Scapy** para abstrair a manipulação de memória e acelerar a dissecção orientada a objetos das camadas de rede.

**Tecnologias e recursos:**
- Python 3
- Scapy (`sniff`, `IP`, `TCP`, `Raw`)
- Captura contínua sem retenção em memória RAM (`store=0`)
- Identificação de portas e *flags* TCP (`'S'`)
- Decodificação segura de payloads brutos (`UTF-8`)

## ⚙️ Funcionamento

O motor do IDS opera seguindo um fluxo contínuo de interceptação e análise:

1. **Descoberta e Abertura da Interface:** identifica a placa de rede ativa e inicia a escuta em Modo Promíscuo.
2. **Interceptação (Callback):** aciona a função de tratamento a cada quadro capturado na interface.
3. **Dissecção da Camada 3 (IP):** extrai os endereços IP de origem e destino e identifica o protocolo encapsulado.
4. **Dissecção da Camada 4 (TCP):** extrai portas de origem/destino e verifica o estado das *flags* de controle.
5. **Detecção de SYN Scan:** dispara um alerta quando identifica pacotes com a flag `SYN` isolada (padrão clássico de *Stealth Scan* do Nmap).
6. **Inspeção da Camada 7 (Payload):** verifica a presença de dados na camada de aplicação e alerta caso identifique requisições HTTP (`GET` ou `POST`) trafegando sem criptografia.

## 🔍 Assinaturas Detectadas

| Assinatura | Camada | Critério de Detecção | Alerta Gerado |
|---|---|---|---|
| **TCP SYN Scan** | Transporte (L4) | Flag `SYN` ativa isoladamente no cabeçalho TCP | Possível início de conexão ou varredura de portas (Nmap `-sS`) |
| **HTTP Cleartext** | Aplicação (L7) | Payload iniciado com os métodos `GET ` ou `POST ` | Requisição HTTP interceptada em texto claro com exibição parcial dos dados |

## 🔧 Como Executar

> **Nota de Permissão:** A ativação do Modo Promíscuo exige privilégios administrativos (`CAP_NET_RAW`) no sistema operacional. Execute ambos os programas utilizando `sudo`.

### Pré-requisitos

**Versão C:**
- GCC ou compilador C compatível.
- Biblioteca de desenvolvimento `libpcap-dev` instalada.

**Versão Python:**
- Python 3.
- Biblioteca `scapy` (`python3-scapy`).

### Versão C

Entre no diretório da implementação:

```bash
cd c
````

Compile vinculando a biblioteca libpcap:

````
gcc ids.c -o ids -lpcap
````

Execute com privilégios de superusuário:

````Bash
sudo ./ids
````

### Versão Python
Entre no diretório da implementação:

````Bash
cd python
````

Instale a dependência (caso não esteja presente no sistema):

````Bash
sudo apt install python3-scapy
````

Execute com privilégios de superusuário:

````Bash
sudo python3 ids.py
````

### 🛡️ Conceitos Praticados

- Network Security e Blue Team
- Encapsulamento de Redes (Modelo OSI / TCP-IP)
- Modo Promíscuo e Captura de Pacotes
- Aritmética de Ponteiros e Estruturação de Memória em C
- Network Byte Order (Big-Endian vs. Little-Endian)
- Operações Bitwise aplicadas a Cabeçalhos TCP
- Inspeção Profunda de Pacotes (DPI)
- Análise de Tráfego e Detecção Baseada em Assinaturas

### 🔭 Próximas Evoluções
---
- Gravação estruturada de alertas em arquivo de log com timestamp.
- Implementação de contagem por janela de tempo (threshold) para reduzir falsos positivos em conexões TCP legítimas.
- Suporte à análise de protocolos adicionais (UDP, ICMP e consultas DNS).
- Exportação de eventos em formato JSON para integração com ferramentas SIEM.

### ⚠️ Aviso de Uso
---
Projeto desenvolvido exclusivamente para fins educacionais e estudos práticos de arquitetura de redes e segurança defensiva.

O monitoramento de tráfego em Modo Promíscuo deve ser realizado apenas em redes próprias ou ambientes de laboratório devidamente autorizados.

---

*Projeto desenvolvido como parte dos meus estudos práticos em Cibersegurança, com foco em Network Security, análise de protocolos e desenvolvimento de ferramentas de defesa.*
