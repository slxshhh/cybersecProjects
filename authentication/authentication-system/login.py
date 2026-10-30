#!/usr/bin/env python3

import hashlib
import json
import getpass

usr = input("Usuário: ")
passw = getpass.getpass("Senha: ")

passw_hashed = hashlib.sha256(passw.encode()).hexdigest()

try:
	with open("users.json", "r") as arquivo:
		loaded_db = json.load(arquivo)
except FileNotFoundError:
	print("[!]Erro, arquivo não encontrado")
	exit()

if loaded_db.get(usr) == passw_hashed:
	print(f"[+]Usuário autenticado com sucesso. Bem vindo {usr}!")
else:
	print("[!]Acesso negado. Usuário ou senha incorretos.")




