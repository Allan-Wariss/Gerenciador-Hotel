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

    printf("CPF: ");
    scanf("%s", cpf);

    printf("Email: ");
    scanf("%s", email);

    printf("Senha: ");
    scanf("%s", senha);

    char caminho_nome[100];
    char caminho_cpf[100];
    char caminho_email[100];
    char caminho_senha[100];

    sprintf(caminho_nome, "cadUsers/nome.txt", nome);
    sprintf(caminho_cpf, "cadUsers/cpf.txt", cpf);
    sprintf(caminho_email, "cadUsers/email.txt", email);
    sprintf(caminho_senha, "cadUsers/senha.txt", senha);

    // Abrir os arquivos para escrita
    FILE* arquivo_nome = fopen(caminho_nome, "a");
    FILE* arquivo_cpf = fopen(caminho_cpf, "a");
    FILE* arquivo_email = fopen(caminho_email, "a");
    FILE* arquivo_senha = fopen(caminho_senha, "a");

    // Verificar se os arquivos foram abertos corretamente
    if (arquivo_nome == NULL || arquivo_cpf == NULL || arquivo_email == NULL || arquivo_senha == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    // Escrever os dados nos arquivos
    fprintf(arquivo_nome, "%s\n", nome);
    fprintf(arquivo_cpf, "%s\n", cpf);
    fprintf(arquivo_email, "%s\n", email);
    fprintf(arquivo_senha, "%s\n", senha);

    // Fechar os arquivos
    fclose(arquivo_nome);
    fclose(arquivo_cpf);
    fclose(arquivo_email);
    fclose(arquivo_senha);

    printf("Cadastro realizado com sucesso!\n");
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
    return 0;
}
