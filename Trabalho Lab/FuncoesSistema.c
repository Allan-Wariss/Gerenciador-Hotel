#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Funções de REGISTRAR QUARTOS
int quar_qtd;
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
            printf("Usuário logado com sucesso!\n");
            fclose(arquivo_nome);
            fclose(arquivo_senha);
            return 1;
        }
    }

    fclose(arquivo_nome);
    fclose(arquivo_senha);

    printf("Nome de usuário ou senha incorretos.\n");
    return 0;

}
// ---------------------------------------------------------------
int main(){
    int escolha;

    do{
        printf("1. Cadastrar novo usuário\n");
        printf("2. Exibir usuários cadastrados\n");
        printf("3. Buscar usuário\n");
        printf("4. Excluir usuário\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                cad_User();
                break;
            
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção invalida!\n");
                break;
        }
        printf("\n");

    }while(escolha != 0);

    Registrar_quartos(5);

    char nome[50];
    char senha[20];

    printf("Digite o nome: ");
    scanf("%s", nome);

    printf("Digite a senha: ");
    scanf("%s", senha);
    verificarLoginUser(nome, senha);

    return 0;
}
