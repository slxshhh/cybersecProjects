#!/usr/bin/env python3

dic = {"192.168.1.1":[22, 21, 443],
	"10.0.0.5":[443, 22],
	"172.16.0.100": [8080, 80, 443, 22, 21]
	}
		
for ip, portas in dic.items():
	for porta in portas:
		print(f"O endereço IP {ip} tem porta: {porta} vulnerável")
