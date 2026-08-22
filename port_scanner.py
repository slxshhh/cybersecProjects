#!/usr/bin/env python3
import socket as sk
import sys
from datetime import datetime

class PortScanner:
	def __init__(self, target, initial_port, final_port):
		self.target = target
		self.initial_port = initial_port
		self.final_port = final_port
		self.open_ports = []

	def show_target(self):
		print(f'-'* 50)
		print(f'\n[+] Alvo da varredura: {self.target}')
		print(f'[+] Range de portas: {self.initial_port} até {self.final_port}')
		print(f'[+] Horário de início: {datetime.now().strftime('%H:%M:%S')}')
		print(f'-' * 50)

	def port_sweep(self):
		for port in range(self.initial_port, self.final_port + 1):
			s = sk.socket(sk.AF_INET, sk.SOCK_STREAM)
			s.settimeout(0.5)
			if s.connect_ex((self.target, port)) == 0:
				self.open_ports.append(port)
			s.close() 

	def show_ports(self):
		print(f'--- Resultado da varredura ---')
		if not self.open_ports:
			print(f'[-] Nenhuma porta aberta foi encontrada')
		else:
			for port in self.open_ports:
				print(f'[!] A porta {port} está aberta')
		print(f'-' * 31)

if __name__ == "__main__":
	scanner = PortScanner('127.0.0.1', 20, 100)
	scanner.show_target()
	scanner.port_sweep()
	scanner.show_ports()

