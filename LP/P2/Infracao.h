/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Infracao.h
 * Author: Bruna Cunha
 *
 * Created on 26 de Fevereiro de 2021, 11:04
 */

#ifndef INFRACAO_H
#define INFRACAO_H
#define NOMEFICHEIRO "infracoes.bin"
typedef struct {
    int dia, mes, ano;
} Data;

typedef enum {
    NORMAL = 1,
            GRAVE 
} TipoInfracao;

  typedef struct {
    int codigo;
    Data data;
    char matricula[12];
    char marca[25];
    char modelo[25];
    char zonaestacionamento[25];
    TipoInfracao tipoinfracao;
    int valorinfracao;
    char nomefuncionario[25];
    char descricao[255];
} Infracao;

//Guarda todos
typedef struct {
    int nrInfracoes;
    int tamanho;
    Infracao *lista; 
} ListaInfracoes;
int iniciarInfracoes(ListaInfracoes *lista, char *nomeficheiro);
void inserirNovaInfracao(ListaInfracoes *lista,char *nomeficheiro);
void inserirInfracaofx(ListaInfracoes lista, char*nomeficheiro);
void atualizarContadorfx(int contador, char *nomeficheiro);
void lerInfracao(Infracao *infra);
void libertarMemoria(ListaInfracoes *lista);
void imprimir(ListaInfracoes *lista);
#endif /* INFRACAO_H */

