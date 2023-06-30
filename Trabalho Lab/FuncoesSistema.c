#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(){
    Registrar_quartos(5);
    return 0;
}
