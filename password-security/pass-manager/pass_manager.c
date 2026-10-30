#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Credencial{
	char servico[50];
        char usuario[50];
        char senha[50];
};
void ofuscar_senhas(char *senha_real){
	char chave = 'K';
	
	for (int i = 0; i < strlen(senha_real); i++){
		senha_real[i] = senha_real[i] ^ chave;
}
};
int main(){
	struct Credencial nova_senha;
	FILE *password_db = fopen("password_db.txt", "a");
	if (password_db == NULL){
		printf("Erro ao abrir\n");
		return 1;
}

	printf("Serviço: ");
	fgets(nova_senha.servico,  50, stdin);
	nova_senha.servico[strcspn(nova_senha.servico, "\n")] = '\0';
	
	printf("Usuário: ");
	fgets(nova_senha.usuario, 50, stdin);
	nova_senha.usuario[strcspn(nova_senha.usuario, "\n")] = '\0';

	printf("Senha: ");
	fgets(nova_senha.senha, 50, stdin);
	nova_senha.senha[strcspn(nova_senha.senha, "\n")] = '\0';
	
	ofuscar_senhas(nova_senha.senha);
	fprintf(password_db, "Serviço: %s | Usuário: %s | Senha %s\n", nova_senha.servico, nova_senha.usuario, nova_senha.senha);		
	printf("[+] Captura realizada com sucesso!");

	fclose(password_db);
	return 0;
}

