#!/usr/bin/env python3

from scapy.all import sniff, IP, TCP, Raw

def packet_handler(packet):
	if packet.haslayer(IP):
		ip_src = packet[IP].src
		ip_dst = packet[IP].dst
		print(f"[IP] : {ip_src} -> {ip_dst}")
		if packet.haslayer(TCP):
			sport = packet[TCP].sport
			dport = packet[TCP].dport
			flags = packet[TCP].flags
			print(f"	[TCP]: Porta {sport} -> {dport} | Flags {flags}")
			if flags == "S":
				print(f"[!!!] ALERTA: pacote TCP SYN detectado ({ip_src}:{sport} -> {ip_dst}:{dport}!")
				print(f"[!!!] Possível port Scan ou Nmap rodando na rede")
			if packet.haslayer(Raw):
				payload = packet[Raw].load.decode('utf-8', errors='ignore')
				if payload.startswith("GET ") or payload.startswith("POST "):
					print("\n[!!!] ALERTA: requisição HTTP interceptada")
					print(f"[*] Dados: \n{payload[:100]}\n")
					
			
print("=== Intrusion Detection System ===")
print("[+] Iniciando captura no modo promíscuo\n")
sniff(prn=packet_handler, store=0)

		
		
