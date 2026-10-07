#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char buffer[50];
	FILE *wordlist = fopen("wordlist.txt","r");
	if (wordlist == NULL){
		printf("Erro ao abrir\n");
		return 1;
}
	while(fgets(buffer, 50, wordlist) != NULL){
		buffer[strcspn(buffer, "\n")] = '\0';
		if (strcmp(buffer, "qwerty") == 0){
			printf("Senha %s foi quebrada.\n", buffer);
			break;
}
		printf("Senha capturada: %s\n", buffer);


}
	fclose(wordlist);
	return 0;
}
