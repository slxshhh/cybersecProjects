#include <stdio.h>
#include <pcap.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <ctype.h>
#include <string.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
	printf("\n[+] Pacote interceptado! Tamanho: %d bytes\n", header->len);
	struct ip *ip_header = (struct ip *)(packet + 14);
	printf("[*] Origem: %s\n", inet_ntoa(ip_header->ip_src));
	printf("[*] Destino: %s\n", inet_ntoa(ip_header->ip_dst));
	int ip_header_len = ip_header->ip_hl * 4;
	if(ip_header->ip_p == 6){
		struct tcphdr *tcp_header = (struct tcphdr *)(packet + 14 + ip_header_len);
		printf("[*] Porta origem: %d\n", ntohs(tcp_header->th_sport));
		printf("[*] Porta destino: %d\n\n", ntohs(tcp_header->th_dport));
		if(tcp_header->th_flags & TH_SYN){
			printf("\n[!] ALERTA!!! Pacote TCP SYN detectado.\n");
			printf("\n[!!!] Possível ínicio de conexão ou Nmap Port Scan!\n\n");
		}
		int tcp_header_len = tcp_header->th_off * 4;
		const u_char *payload = packet + 14 + ip_header_len + tcp_header_len;
		int payload_len = header->len - (14 + ip_header_len + tcp_header_len);
		if(payload_len > 0){

					printf("[DEBUG] Início do Payload: %c%c%c%c\n",
						isprint(payload[0]) ? payload[0] : '.',
						isprint(payload[1]) ? payload[1] : '.',
						isprint(payload[2]) ? payload[2] : '.',
						isprint(payload[3]) ? payload[3] : '.');
					

					if(strncmp((const char *)payload, "GET ", 4) == 0 || strncmp((const char*)payload, "POST ", 5) == 0){
						printf("\n[!!!] ALERTA: requisicao HTTP interceptada!\n");
						printf("[*] Dados: \n");
						
						for(int i = 0; i < payload_len && i < 50; i++){
							
							if(isprint(payload[i]) || payload[i] == '\n' || payload[i] == '\r'){
								putchar(payload[i]);
							} else {
								putchar('.');
							}
						}
						printf("\n\n");
					}
				}


		}
}

int main(){
	char errbuf[PCAP_ERRBUF_SIZE];
	char *device;
	pcap_t *handle;

	device = pcap_lookupdev(errbuf);

	printf("=== Intrusion Detection System ===\n\n");

	if(device == NULL){
		printf("[!] Erro: %s\n", errbuf);
	} else{
		printf("[+] Placa de rede monitorada: %s\n", device);
	}

	handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);
	
	// 1. CHECAGEM DE SEGURANÇA VEM PRIMEIRO!
	if(handle == NULL){
		printf("\n[!] Não foi possível abrir a placa: %s\n", errbuf);
		return 2;
	}

	// 2. CORREÇÃO DA ASPA DO PRINTF
	if(pcap_datalink(handle) != DLT_EN10MB){
		printf("\n[!] AVISO: a interface %s não usa cabeçalho Ethernet (14 bytes)\n", device);
		printf("[!] O tipo de link retornado foi %d\n", pcap_datalink(handle));
	}

	printf("\n[*] Sessão de captura iniciada em Modo Promíscuo!\n");

	pcap_loop(handle, 0, packet_handler, NULL);

	pcap_close(handle);

	return 0;
}