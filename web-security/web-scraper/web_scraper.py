#!/usr/bin/env python

from bs4 import BeautifulSoup
import requests

resposta = requests.get('https://quotes.toscrape.com/')

if resposta.status_code == 200:
	sopa = BeautifulSoup(resposta.text, 'html.parser')
	print('[+] Entrou no site!')
	print(f'[+] Nome do site: {sopa.title.text}')
	for link in sopa.find_all('a'):
		print(f'{link.get('href')}')
else:
	print(f'[!] Erro: {resposta.status.code}')

