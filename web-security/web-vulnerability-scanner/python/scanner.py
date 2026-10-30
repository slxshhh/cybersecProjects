#!/usr/bin/env python3

import requests
import re
import csv

print(50 * "-")
print("[+] Web Vulnerabilities Scanner")
print(50 * "-")
with open('rules.csv', 'r') as file, open('report.txt', 'w') as report:
	report.write("=== Vulnerabilities Report ===\n\n")
	file_read = csv.reader(file)
	for line in file_read:
		if not line:
			continue

		method, name, payload, regex_pattern = line

		if method == "GET":
			url = "http://httpbin.org/get"
			response = requests.get(url, params={'id': payload})
		elif method == "POST":
			url = "http://httpbin.org/post"
			response = requests.post(url, data={'id': payload})

		answer = re.search(regex_pattern, response.text, re.IGNORECASE)
		if answer:
			print(f"[!] VULNERABILIDADE ENCONTRADA: {name}!")
			report.write(f"[+] Falha reportada: {name}\n")
			report.write(f"[+] Método: {method}\n")
			report.write(f"[+] Payload: {payload}\n")
			report.write(f"[+] Regex: {regex_pattern}\n\n")
			print(50 * "-")
		else:
			print(f"[+] Nome: {name}")
			print(f"[+] Método: {method}")
			print(f"[+] Payload: {payload}")
			print(f"[+] Regex: {regex_pattern}")
			print("[-] Alvo seguro contra esse payload")
			print(50 * "-")
