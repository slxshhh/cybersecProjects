#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Crypto{
	char message[50];
	char key;
};

void xor(char *text, char key){
	for(int i = 0; i < strlen(text); i++){
		text[i] = text[i] ^ key;
}
};

int main(){
	struct Crypto new_crypto;

	printf("Mensagem: ");
	fgets(new_crypto.message, 50, stdin);
	new_crypto.message[strcspn(new_crypto.message, "\n")] = '\0';

	printf("Chave: ");
	scanf(" %c", &new_crypto.key);

	printf("[+] Mensagem original: %s\n", new_crypto.message);

	xor(new_crypto.message, new_crypto.key);

	printf("[+] Mensagem criptografada: %s\n", new_crypto.message);

	xor(new_crypto.message, new_crypto.key);

	printf("[+] Mensagem descriptografada: %s\n", new_crypto.message);

	return 0;
}

