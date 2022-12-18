#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}Elemento;

typedef struct pilha{
    Elemento *topo;
}Pilha;

void criarP(Pilha *x){
    x->topo = NULL;
}

bool vaziaP(Pilha *x){
    if(x->topo == NULL){
        return true;
    }else{
        return false;
    }
}

bool empilha(Pilha *x, int valor){
    Elemento *y = (Elemento*) malloc(sizeof(Elemento));
    if(y != NULL){
        y->valor = valor;
        y->prox = x->topo;
        x->topo = y;
        return true;
    }else{
        return false;
    }
}

bool desempilha(Pilha *x, int *valor){
    if(!vaziaP(x)){
        Elemento *y = x->topo;
        x->topo = y->prox;
        y->prox = NULL;
        *valor = y->valor;
        free(y);
        return true;
    }else{
        return false;
    }
}