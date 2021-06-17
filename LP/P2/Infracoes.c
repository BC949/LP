/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



#include <stdio.h>
#include <stdlib.h>
#include "Infracao.h"

void cleanInputBuffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}


void libertarMemoria(ListaInfracoes *lista) {
    free(lista->lista);
    lista->lista = NULL;
}
void expandirMemoria(ListaInfracoes *lista){
    Infracao *tmp = (Infracao *) realloc (lista->lista,sizeof(Infracao) * (lista->tamanho * 2));
    if(tmp != NULL){
        lista->lista = tmp;
        lista->tamanho *= 2;
    }else{
        exit(EXIT_FAILURE);
    }
}
void atualizarContadorfx(int contador, char *nomeficheiro) {
    FILE *fp = fopen(nomeficheiro, "r+b");
    if (fp != NULL) {
        fwrite(&contador, sizeof (int), 1, fp);
        fclose(fp);
    }
}

int iniciarInfracoes(ListaInfracoes *lista, char *nomeficheiro) {
    int sucesso = 0;
    FILE *fp = fopen(nomeficheiro, "rb");
    if (fp != NULL) {
        fread(&lista->nrInfracoes, sizeof (int), 1, fp);
        if (lista->nrInfracoes > 0) {
            lista->lista = (Infracao*) malloc(lista->nrInfracoes * sizeof (Infracao));
            fread(lista->lista, sizeof (Infracao), lista->nrInfracoes > 0, fp);
            lista->tamanho = lista->nrInfracoes;
            sucesso = 1;

        }
        fclose(fp);
    }

    if (!sucesso) {
        fp = fopen(nomeficheiro, "wb");
        lista->lista = (Infracao*) malloc(5 * sizeof (Infracao));
        lista->nrInfracoes = 0;
        lista->tamanho = 5;
        fclose(fp);
    }
}

void inserirInfracaofx(ListaInfracoes lista, char*nomeficheiro) {
    atualizarContadorfx(lista.nrInfracoes, nomeficheiro);
    FILE *fp = fopen(nomeficheiro, "ab");
    if (fp != NULL) {
        fwrite(&lista.lista[lista.nrInfracoes - 1], sizeof (Infracao), 1, fp);
        fclose(fp);
    }
}

void lerInfracao(Infracao *infra) {
    cleanInputBuffer();
    int dia, mes, ano,tipoinfracao;
    puts("Matricula:");
    fgets(infra->matricula, 12, stdin);
    puts("Marca :");
    fgets(infra->marca, 25, stdin);
    puts("Modelo:");
    fgets(infra->modelo, 25, stdin);
    puts("Zona Estacionamento:");
    fgets(infra->zonaestacionamento, 25, stdin);
    puts("Nome Funcionario:");
    fgets(infra->nomefuncionario, 25, stdin);
     puts("Descricao :");
    fgets(infra->descricao, 255, stdin);
    
    puts("Valor Infraçao:");
    scanf("%d",&infra->valorinfracao);
    //Leitura dia
    do {
        printf("Dia Trabalho! \n");
        scanf("%d", &dia);
        if (dia < 0 || dia > 32) {
            puts("Invalido");
        }
    } while (dia < 0 || dia > 32);
    infra->data.dia = dia;
    do {
        printf("Mês ! \n");
        scanf("%d", &mes);
        if (mes < 0 || mes > 13) {
            puts("Invalido");
        }
    } while (mes < 0 || mes > 13);
    infra->data.mes = mes;

    //Leitura ano
    do {
        printf("Ano ! \n");
        scanf("%d", &ano);
        if (ano < 1970 || ano > 2020) {
            puts("Invalido");
        }
    } while (ano < 1970 || ano > 2020);
    infra->data.ano = ano;
    // tipo infracao
     do {
        printf("Tipo infracao 1-Normal 2- Grave ! \n");
        scanf("%d", &ano);
        if (tipoinfracao != 1 && tipoinfracao != 2) {
            puts("Invalido");
        }
    } while (tipoinfracao != 1 && tipoinfracao != 2);
    infra->tipoinfracao = tipoinfracao;
}

void inserirNovaInfracao(ListaInfracoes *lista, char*nomeficheiro) {
Infracao infra;
if(lista->nrInfracoes == 0){
    infra.codigo = 1;
}else{
 infra.codigo = lista->lista[lista->nrInfracoes -1].codigo + 1;   
}
 lerInfracao(&infra);
 if(lista->nrInfracoes == lista->tamanho){
     expandirMemoria(lista);
 }
 lista->lista[lista->nrInfracoes] = infra;
 lista->nrInfracoes++;
 inserirInfracaofx(*lista,nomeficheiro);
}

void obterTotalInfracoesData(ListaInfracoes * lista){
     int dia, mes, ano;
     do {
        printf("Dia Trabalho! \n");
        scanf("%d", &dia);
        if (dia < 0 || dia > 32) {
            puts("Invalido");
        }
    } while (dia < 0 || dia > 32);
    do {
        printf("Mês ! \n");
        scanf("%d", &mes);
        if (mes < 0 || mes > 13) {
            puts("Invalido");
        }
    } while (mes < 0 || mes > 13);
    //Leitura ano
    do {
        printf("Ano ! \n");
        scanf("%d", &ano);
        if (ano < 1970 || ano > 2020) {
            puts("Invalido");
        }
    } while (ano < 1970 || ano > 2020);
  
}
void imprimir(ListaInfracoes *lista){
    for(int i = 0; i < lista->nrInfracoes; i++){
        printf("Codigo: %d\n",lista->lista[i].codigo);
    }
}