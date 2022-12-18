#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct elemento{
    float valor;
    struct elemento *prox;
}Elemento;

typedef struct pilha{
    Elemento *topo;
}Pilha;

void criar(Pilha *x){
    x->topo = NULL;
}

bool vazia(Pilha *x){
    if(x->topo == NULL){
        return true;
    }else{
        return false;
    }
}

bool empilha(Pilha *x, float valor){
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

bool desempilha(Pilha *x, float *valor){
    if(!vazia(x)){
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

float operacao(float x, float y, char z){
    switch (z)
    {
    case '+': return x + y; break;
    case '-': return x - y; break;
    case '*': return x * y; break;
    case '/': return x / y; break;
    case '^': return pow(x, y); break;
    default: return 0.0;
    }
}

float resolve(char exp[]){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    float x, y, res;
    char *exptok;
    criar(p);
    exptok = strtok(exp, " ");
    while(exptok != NULL){
        if(exptok[0] == '+' || exptok[0] == '-' || exptok[0] == '*' || exptok[0] == '/' || exptok[0] == '^'){
            desempilha(p, &y);
            desempilha(p, &x);
            res = operacao(x, y, exptok[0]);
            empilha(p, res);
        }else{
            res = (float)strtol(exptok, NULL, 10);
            empilha(p, res);
        }
        exptok = strtok(NULL, " ");
    }
    desempilha(p, &res);
    return res;
    
}

int main(){
    char str[50] = {"5 3 2 + * 4 / 6 -"};
    float result;
    printf("Resultado de %s: ", str);
    result = resolve(str);
    printf("%.2f\n", result);
    return 0;
}
