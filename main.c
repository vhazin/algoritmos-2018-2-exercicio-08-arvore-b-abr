//
//  main.c
//  Arvore B Hazin
//
//  Created by Bernardo Russo on 08/10/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int leitura (){
    int n;
    scanf("%d",&n);
    return n;
}

typedef struct btree{
    int n;
    int folhas;
    
}btree;

int main (){
    int n,add;
    printf ("Digite o valor da ordem: ");
    n=leitura();
    printf ("\n Digite os valores a serem inseridos na arvore, digite 0 para finalizar entradas: ");
    do{
        scanf("%d",&add);
        if (add == 0)
            break;
        
    }while(1);
    return 0;
}

/*
typedef struct folha{
    int id;
    int altura;
    int ordem;
    struct no *direita;
    struct no *esquerda;
    struct folha *raiz;
    int idfolha;
}folha;


typedef struct no{
    folha *esquerda;
    folha *direita;
}no;

typedef struct arvb{
    int tamanho;
    folha *raiz;
}arvb;


void criararvb(){
    folha *x=malloc(sizeof(folha));
    x->idfolha=1;
    x->nivel=0;
    
}

void addarvb(folha *x, int k){
    int i;
    i=x->id;
    
}


int main() {
    int n;
    printf("digite a ordem da arvore: ");
    scanf("%d",&n);
    
    return 0;
}*/
