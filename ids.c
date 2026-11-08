#include <stdio.h>
#include <pcap.h>

void packet_handler(u_char *args, const struct pcap_pkthdr *header, const u_char *packet){
	printf("\n[+] Pacote interceptado! Tamanho: %d bytes\n", header->len);

}

int main(){
	char errbuf[PCAP_ERRBUF_SIZE];
	char *device;
	pcap_t *handle;

	device = pcap_lookupdev(errbuf);

	printf("=== Intrusion Detection System ===\n\n");

	if(device == NULL){
		printf("%s", errbuf);
	} else{
		printf("[+] Placa de rede monitorada: %s ", device);
	}

	handle = pcap_open_live(device, BUFSIZ, 1, 1000, errbuf);

	if(handle == NULL){
		printf("\n[!] Não foi possível abrir");
		return 2;
	}
	printf("\n[*] Sessão de captura iniciada em Modo Promíscuo!\n");

	pcap_loop(handle, 0, packet_handler, NULL);

	pcap_close(handle);

	return 0;
}
