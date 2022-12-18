#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct elemento{
    int valor;
    struct elemento *prox;
}Elemento;


typedef struct fila{
    Elemento *primeiro;
    Elemento *ultimo;
}Fila;

void criar(Fila *x){
    x->primeiro = NULL;
    x->ultimo = NULL;
}

bool vazia(Fila x){
    if(x.primeiro == NULL){
        return true;
    }else{
        return false;
    }
}

bool inserir(Fila *x, int valor){
    Elemento *y = (Elemento*) malloc(sizeof(Elemento));
    if(y == NULL){
        return false;
    }else{
        y->valor = valor;
        y->prox = NULL;
        if(x->primeiro == NULL){
            x->primeiro = y;
        }else{
            x->ultimo->prox = y;
        }
        x->ultimo = y;
        return true;
    }
}

bool retirar(Fila *x, int *valor){
    Elemento *y = x->primeiro;
    if(y == NULL){
        return false;
    }else{
        x->primeiro = y->prox;
        y->prox = NULL;
        *valor = y->valor;
        free(y);
        if(x->primeiro == NULL){
            x->ultimo = NULL;
        }
        return true;
    }
}