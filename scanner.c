#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <regex.h>

struct Rule{
    char name[64];
    char payload[128];
    char regex_pattern[128];
    char method[8];
};

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
    char line[256];
    CURL *curl;
    CURLcode res;
    const char *base_url = "http://httpbin.org/get?id=";
    
    // CORREÇÃO: Inicializado com zeros para evitar lixo de memória
    char target_url[256] = {0};

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    FILE *file = fopen("rules.csv", "r");
    if (file == NULL){
        printf("[!] Erro ao abrir o arquivo rules.csv\n");
        return 1;
    }

    // MÓDULO 4: Criando o arquivo de relatório
    FILE *report = fopen("report.txt", "w");
    if (report == NULL) {
        printf("[!] Erro ao criar o arquivo report.txt\n");
        fclose(file);
        return 1;
    }
    fprintf(report, "=== Relatório de Vulnerabilidades (Scanner V1) ===\n\n");

    printf("[+] Web Vulnerability Scanner - Automacao Iniciada\n\n");

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl){
        while (fgets(line, sizeof(line), file)){
            struct Rule current_rule = {0};

            // Limpa quebra de linha do Linux (\n) e do Windows (\r) caso exista
            line[strcspn(line, "\r\n")] = '\0';
            if (strlen(line) == 0) continue; 

            char *token = strtok(line,",");
            if (token != NULL){
                strncpy(current_rule.method, token, sizeof(current_rule.method) -1 );
                current_rule.method[sizeof(current_rule.method) -1] = '\0';
            }
            
            token = strtok(NULL, ",");
            if (token != NULL){
                strncpy(current_rule.name, token, sizeof(current_rule.name) -1);
                current_rule.name[sizeof(current_rule.name) - 1] = '\0';
            }

            token = strtok(NULL, ",");
            if (token != NULL){
                strncpy(current_rule.payload, token, sizeof(current_rule.payload) -1);
                current_rule.payload[sizeof(current_rule.payload) - 1] = '\0';
            }

            token = strtok(NULL, ",");
            if (token != NULL){
                strncpy(current_rule.regex_pattern, token, sizeof(current_rule.regex_pattern) - 1);
                current_rule.regex_pattern[sizeof(current_rule.regex_pattern) - 1] = '\0';
            }

            printf("[*] Regra Parseada: [%s] %s\n", current_rule.method, current_rule.name);

            // Monta a URL
            if (strcmp(current_rule.method, "GET") == 0){
                snprintf(target_url, sizeof(target_url),"http://httpbin.org/get?id=%s", current_rule.payload);
            } else if(strcmp(current_rule.method, "POST") == 0){
                snprintf(target_url, sizeof(target_url), "http://httpbin.org/post");
            } else {
                // TRAVA DE SEGURANÇA: Se o método não for GET nem POST (ex: Path_Traversal cru), pula a linha!
                printf("[-] Erro de sintaxe na regra. Método '%s' inválido. Pulando...\n\n", current_rule.method);
                continue; 
            }

            chunk.size = 0;

            curl_easy_setopt(curl, CURLOPT_URL, target_url);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

            printf("[*] Testando URL: %s\n", target_url);
            
            if (strcmp(current_rule.method, "POST") == 0){
                curl_easy_setopt(curl, CURLOPT_POST, 1L);
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, current_rule.payload);
            } else {
                curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
            }

            res = curl_easy_perform(curl);

            if(res != CURLE_OK){
                fprintf(stderr, "[-] Erro na requisição: %s\n", curl_easy_strerror(res));
            } else {
                regex_t regex;
                int reti;

                reti = regcomp(&regex, current_rule.regex_pattern, REG_ICASE | REG_EXTENDED);
                if (reti){
                    fprintf(stderr, "[-] Falha ao compilar a expressão regular.\n");
                } else {
                    reti = regexec(&regex, chunk.memory, 0, NULL, 0);
                    
                    if(!reti){
                        printf("[!!!] VULNERABILIDADE ENCONTRADA: %s!\n\n", current_rule.name);
                        
                        // MÓDULO 4: Gravando no Relatório
                        fprintf(report, "[+] FALHA DETECTADA: %s\n", current_rule.name);
                        fprintf(report, "    Método: %s\n", current_rule.method);
                        fprintf(report, "    URL Alvo: %s\n", target_url);
                        fprintf(report, "    Payload Injetado: %s\n", current_rule.payload);
                        fprintf(report, "    Assinatura (Regex): %s\n\n", current_rule.regex_pattern);
                        fflush(report); // Força gravação no disco

                    } else if(reti == REG_NOMATCH){
                        printf("[-] Alvo seguro contra este payload.\n\n");
                    } else {
                        printf("[-] Erro desconhecido ao executar a regex.\n\n");
                    }
                    regfree(&regex);
                }
            }
        }
        curl_easy_cleanup(curl);
    }

    fclose(file);
    fclose(report); // Fecha o relatório
    free(chunk.memory);
    curl_global_cleanup();

    printf("[+] Scanner finalizado. Verifique o arquivo report.txt\n");

    return 0;
} 

