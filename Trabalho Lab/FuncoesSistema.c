#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


// Funções de REGISTRAR QUARTOS
int quar_qtd;
char *user_atual;
bool logado = false;
void quantidade(){
    FILE * QuartoQTD = fopen("quartos/quartoQTD.txt", "r");
    fscanf(QuartoQTD, "%d", &quar_qtd);
    fclose(QuartoQTD);
}


void criando_quarto(){
    quantidade();
    quar_qtd += 1;
    
    FILE * QuartoQTD = fopen("quartos/quartoQTD.txt", "w");
    fprintf(QuartoQTD, "%d", quar_qtd);
    fclose(QuartoQTD);

    char quarto[50]= "quartos/quarto";
    char txt[50]= ".txt";
    char quar_qtdStr[50];
    sprintf(quar_qtdStr, "%d", quar_qtd);
    strcat(quarto, quar_qtdStr);
    strcat(quarto,txt);
    FILE * Quarto = fopen(quarto, "w");
    fclose(Quarto);
}


void Registrar_quartos(int qnt){
    quantidade();
    printf("%d\n", quar_qtd);

    for (int i = 1 ; i <= qnt; i++) {
        criando_quarto();
    }

    quantidade();
    printf("%d\n", quar_qtd);
}
//-----------------------------------------------

// Função para cadastrar um usuário
void cad_User() {
    char nome[100];
    char cpf[11];
    char email[100];
    char senha[20];

    printf("Nome: ");
    scanf("%s", nome);

    printf("Senha: ");
    scanf("%s", senha);

    char caminho_nome[100];
    char caminho_cpf[100];
    char caminho_email[100];
    char caminho_senha[100];

    sprintf(caminho_nome, "cadUsers/nome.txt", nome);
    sprintf(caminho_senha, "cadUsers/senha.txt", senha);

    // Abrir os arquivos para escrita
    FILE* arquivo_nome = fopen(caminho_nome, "a");
    FILE* arquivo_senha = fopen(caminho_senha, "a");

    // Verificar se os arquivos foram abertos corretamente
    if (arquivo_nome == NULL || arquivo_senha == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    // Escrever os dados nos arquivos
    fprintf(arquivo_nome, "%s\n", nome);
    fprintf(arquivo_senha, "%s\n", senha);

    // Fechar os arquivos
    fclose(arquivo_nome);
    fclose(arquivo_senha);

    printf("Cadastro realizado com sucesso!\n");
}
// ---------------------------------------------------------------

// Função para verificar registro de cadastro dos usuários
int verificarLoginUser(const char* nome, const char* senha){
    FILE* arquivo_nome = fopen("cadUsers/nome.txt", "r");
    FILE* arquivo_senha = fopen("cadUsers/senha.txt", "r");

    if (arquivo_nome == NULL || arquivo_senha == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 0;
    }

    char linha_nome[50];
    char linha_senha[20];

    int linha = 1;
    for (linha = 1; fgets(linha_nome, sizeof(linha_nome), arquivo_nome) != NULL
     && fgets(linha_senha, sizeof(linha_senha), arquivo_senha) != NULL; linha++) {
        linha_nome[strcspn(linha_nome, "\n")] = '\0';
        linha_senha[strcspn(linha_senha, "\n")] = '\0';

        if (strcmp(linha_nome, nome) == 0 && strcmp(linha_senha, senha) == 0) {
            printf("Usuario logado com sucesso!\n");
            user_atual = nome;
            logado = true;
            fclose(arquivo_nome);
            fclose(arquivo_senha);
            printf("\nBem-vindo %s\n",user_atual);
            return 1;
        }
    }

    fclose(arquivo_nome);
    fclose(arquivo_senha);

    printf("\nNome de usuario ou senha incorretos.\n");
    return 0;

}
// ---------------------------------------------------------------


int main(){
    int escolha;
    int quantidade;
    char nome[50];
    char senha[20];

//Tela de login
    do{
        printf("1. Logar\n");
        printf("2. Registrar usuario\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d",&escolha);
        printf("\n");
                        
        switch (escolha)
        {
                        
            case 1:
                printf("Digite o nome: ");
                scanf("%s", nome);
                printf("Digite a senha: ");
                scanf("%s", senha);
                verificarLoginUser(nome, senha);
                escolha = 0;
                break;
            case 2:
                cad_User();
            
            case 0:
                printf("Saindo do sistema...\n");
                
            default:
                break;
        }
                
    }while (escolha !=0);

escolha = 100; //Resetar valor de escolha e não dar conflito no proximo loop
    

    //Tela do sistema
    if(logado == true){
        do{
            printf("1. Cadastrar novo Quarto\n");
            printf("2. Exibir usuarios cadastrados\n");
            printf("3. Exibir quartos cadastrados\n");
            printf("4. ChekIn\n");
            printf("5. ChekOut\n");
            printf("6. LOGAR\n");
            printf("0. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &escolha);

            switch(escolha){
                
                case 2:
                    printf("Quantos quartos deseja Registrar?: ");
                    scanf("%d",&quantidade);
                    printf("\n");

                    Registrar_quartos(quantidade);
                case 0:
                    printf("Saindo do sistema...\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }
            printf("\n");

        }while(escolha != 0);   
    }
    else{
        printf("\nErro ao entrar no SISTEMA\n");
    }
    
    return 0;
}
