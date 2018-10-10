//
//  main.c
//  Arvore B Hazin
//
//  Created by Bernardo Russo on 08/10/18.
//  Copyright © 2018 Bernardo Russo. All rights reserved.
//

#include <stdio.h>
typedef struct folha{
    int id;
    int nivel;
    struct folha *direita;
    struct folha *esquerda;
    struct folha *raiz;
    int idfolha;
}folha;

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
}
