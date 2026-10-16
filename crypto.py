#!/usr/bin/env python3

from cryptography.fernet import Fernet

key = Fernet.generate_key()
engine = Fernet(key)

message = input("[+] Mensagem: ")

encoded_message = message.encode()

encrypted_message = engine.encrypt(encoded_message)

print(f"[+] Chave gerada: {key}")
print(f"[+] Mensagem criptografada: {encrypted_message}")

decrypted_message = engine.decrypt(encrypted_message).decode()

print(f"[+] Mensagem descriptografada: {decrypted_message}")




