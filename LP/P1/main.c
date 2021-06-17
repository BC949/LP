/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Bruna Cunha
 *
 * Created on 26 de Fevereiro de 2021, 9:50
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_PRODUTOS 5
#define MAX_ARMAZENS 4


void inserirDados(int stocks[MAX_ARMAZENS][MAX_PRODUTOS],int armazens,int produtos){
    int numero;
    for(int i = 0; i < armazens ; i++){
       
        for(int j = 0; j < produtos;j++){
            do{
                puts("Numero de Stock");
                scanf("%d",&numero);
                if(numero < 0){
                    puts("Invalido");
                }
            }while(numero <= 0);
            stocks[i][j] = numero;
        }
    }
}
void obterPercentagem(int stocks[MAX_ARMAZENS][MAX_PRODUTOS],int armazens,int produtos){
    int total = 0;
    float percentagem;
    for(int i = 0; i < armazens ; i++){
        for(int j = 0; j < produtos;j++){
            total += stocks[i][j] ;
        }
    }
    //Percentagem
    for(int i = 0; i < armazens ; i++){
        for(int j = 0; j < produtos;j++){
          percentagem =(float) stocks[i][j] / total ;
          percentagem *= 100;
          printf("Percentagem : %f\n",percentagem);
        }
    }
}
int totalStockProduto (int stocks[MAX_ARMAZENS][MAX_PRODUTOS], int produto){
    int total = 0;
    for(int i = 0; i < MAX_ARMAZENS ; i++){
        for(int j = 0; j < MAX_PRODUTOS;j++){
            if(j == produto){
                total = total + stocks[i][j];
            }
        }
    }
   return total; 
}
int verificaStockMinimo (int stocks[MAX_ARMAZENS][MAX_PRODUTOS], int stock_minimo[]){
    int total = 0;
    
    for(int i = 0; i < MAX_PRODUTOS; i++){
        printf("Produto %d\n",i);
        printf("Abaixo do stock em:");
        for(int j = 0; j < MAX_ARMAZENS; j++){
             if(stock_minimo[i] > stocks[i][j]){
                 printf("Armazen %d , ",j+ 1);
             }   
        }
        puts(" ");
    
    }
}
int main(int argc, char** argv) {
    int stocks [MAX_ARMAZENS] [MAX_PRODUTOS];
    int stock_minimo[5];
    int totalstock;
    inserirDados(stocks,MAX_ARMAZENS,MAX_PRODUTOS);
    obterPercentagem(stocks,MAX_ARMAZENS,MAX_PRODUTOS);
    totalstock = totalStockProduto(stocks,4);
    printf("\n Total stock %d \n",totalstock);
    for(int i = 0; i < 5; i++){
        printf("Valor minimo produto %d \n",i + 1);
        scanf("%d",&stock_minimo[i]);
    }
    verificaStockMinimo(stocks,stock_minimo);
    return (EXIT_SUCCESS);
}