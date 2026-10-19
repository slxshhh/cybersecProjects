#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <regex.h>

struct MemoryStruct{
	char *memory;
	size_t size;
};

size_t Callback(void *contents, size_t size, size_t nmemb, void *userp){
	size_t realsize = size * nmemb;

	struct MemoryStruct *mem = (struct MemoryStruct *)userp;

	char *ptr = realloc(mem->memory, mem->size + realsize + 1);

	if(ptr == NULL){
		printf("Falta de memória!\n");
		return 0;

}
	mem->memory = ptr;

	memcpy(&(mem->memory[mem->size]), contents, realsize);

	mem->size += realsize;
	mem->memory[mem->size] = 0;

	return realsize;
}

int main(int argc, char *argv[]){
	CURL *curl;
	CURLcode res;
	const char *base_url = "http://httpbin.org/get?id=";
	const char *payload = "'";
	char target_url[256];	

	struct MemoryStruct chunk;
	chunk.memory = malloc(1);
	chunk.size = 0;

	snprintf(target_url, sizeof(target_url), "%s%s", base_url, payload);

	printf("[+] Web Vulnerability Scanner\n");
	printf("[+] Alvo configurado: %s\n\n", target_url);

	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl){
		curl_easy_setopt(curl, CURLOPT_URL, target_url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

		printf("[*] Disparando GET\n");
		printf("[*] Testando URL: %s\n", target_url);
		res = curl_easy_perform(curl);

		if(res != CURLE_OK){
			fprintf(stderr, "\n[-] Erro na requisição: %s\n", curl_easy_strerror(res));
		}else {
			printf("\n[+] Requisição finalizada com sucesso! Tamanho em memória: %lu bytes\n", (unsigned long)chunk.size);
			regex_t regex;
			int reti;
			
			reti = regcomp(&regex, "args|httbin", REG_ICASE | REG_EXTENDED);
			if (reti){
				fprintf(stderr, "[-] Falha ao compilar a expressão regular.\n");
			}else{
				reti = regexec(&regex, chunk.memory, 0, NULL, 0);
				
				if(!reti){
					printf("\n[!!!] VULNERABILIDADE ENCONTRADA! Assinatura detectada no HTML.\n");
				}else if(reti == REG_NOMATCH){
					printf("\n[-] Alvo parece seguro contra esse payload. Nenhuma assinatura encontrada.\n");
				}else {
					printf("\n[-] Erro desconhecido ao executar a regex.\n");
				}
			regfree(&regex);


			}
			printf("[+] Conteúdo interceptado: \n%s\n", chunk.memory);
		}
		curl_easy_cleanup(curl);

	free(chunk.memory);
	
	curl_global_cleanup();

	return 0;
}

}
