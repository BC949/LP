/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Bruna Cunha
 *
 * Created on 26 de Fevereiro de 2021, 11:04
 */


#include <stdio.h>
#include <stdlib.h>
#include "Infracao.h"
int main(int argc, char** argv) {
    int op;
    ListaInfracoes lista;
    iniciarInfracoes(&lista,NOMEFICHEIRO);
     do {
        puts("----------");
        puts("----------");
        puts("1. Inserir Infracao");
        puts("2.Obter por data");
        puts("3.Listar");
        puts("0.Sair");
        puts("Insira a sua opção:");
        printf("Numero Infraçoes: %d / %d \n ",lista.nrInfracoes,lista.tamanho);
        scanf("%d", &op);
        switch (op) {
            case 1:
              inserirNovaInfracao(&lista,NOMEFICHEIRO);
                break;
            case 2:
                obterTotalInfracoesData(&lista);
                break;
            case 3:
                imprimir(&lista);
                break;
            default:
                puts("Opção inválida!");
                break;
        }
    } while (op != 0);
libertarMemoria(&lista);
    return (EXIT_SUCCESS);
}

