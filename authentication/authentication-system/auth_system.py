#!/usr/bin/env python3

import hashlib 
import json 
import getpass

usr = str(input("Usuário: "))
passw = getpass.getpass("Senha: ")
users_db = {}

passw_hashed = hashlib.sha256(passw.encode()).hexdigest()
users_db[usr] = passw_hashed

with open("users.json", "w") as arquivo:
	json.dump(users_db, arquivo, indent=4)

print(f"[+] Hash gerado com sucesso: {passw_hashed}")
