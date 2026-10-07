#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main(){
	char alvo[] = "21232f297a57a5a743894a0e4a801fc3";
	unsigned char resultado[MD5_DIGEST_LENGTH];
	char buffer[50];
	char hash_convertido[33];

	FILE *wordlist = fopen("wordlist.txt", "r");
	if (wordlist == NULL){
		printf("[!] Erro ao abrir");
		return 1;
}
	while(fgets(buffer, 50, wordlist) != NULL){
		buffer[(strcspn(buffer, "\n"))] = '\0';
		MD5(buffer, strlen(buffer), resultado);
		for(int i = 0; i < MD5_DIGEST_LENGTH; i++){
			sprintf(&hash_convertido[i * 2], "%02x", resultado[i]);

}
		printf("[+] Alvo: %s\n", alvo);
		printf("[+] Hash convertido: %s\n", hash_convertido);

		if (strcmp(alvo, hash_convertido) == 0){
			printf("[+] Hash encontrado, a senha é: %s", buffer);
			break;

}		 else{
			printf("[!] Alvo não encontrado.\n");
			printf("-----------------------------------------------------------\n");
}
}
	fclose(wordlist);
	return 0;
}


