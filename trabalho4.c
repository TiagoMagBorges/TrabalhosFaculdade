#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

long long int fibit(x){
    long long int prim = 0, seg = 1, res;
    for(int i = 0; i < x; i++){
        res = prim + seg;
        prim = seg;
        seg = res;
    }
    return prim;
}

long long int fibrec(x){
    if(x == 1){
        return 0;
    }else if(x == 2){
        return 1;
    }else {
        return fibrec(x - 1) + fibrec(x - 2);
    }
}

float imc(float massa, float altura){
    return (massa / (altura*altura));
}

long long int somatorio(int n){
    long long int soma = 0;
    for(int i = 1; i <= n; i++){
        soma += pow(i, i);
    }
    return soma;
}

void decrescente(x){
    if(x == 0){
        printf("0\n");
    }else{
        printf("%d\n", x);
        decrescente(x-1);
    }
}

void crescente(x){
    if(x == 0){
        printf("0\n");
    }else{
        crescente(x-1);
        printf("%d\n", x);
    }
}

float **aloca(int linha, int coluna){
    float **m = (float**) malloc(linha* sizeof(float*));
    for(int i = 0; i < linha; i++){
        m[i] = (float*) malloc(coluna* sizeof(float));
    }

    return m;
}

void leitura(float **matriz, int linha, int coluna){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("Insira um valor para Matriz[%d][%d]: \n", i, j);
            scanf("%f", &matriz[i][j]);
        }
    }
}

float **multiplica(float **matriz1, int linha1, int coluna1, float **matriz2, int linha2, int coluna2){
    float **matriz3 = aloca(linha1, coluna2), soma = 0;
    for(int i = 0; i < linha1; i++){
        for(int j = 0; j < coluna2; j++){
            soma = 0;
            for(int k = 0; k < linha2; k++){
                soma += matriz1[i][k] * matriz2[k][j];
            }
            matriz3[i][j] = soma;
        }
    }

    return matriz3;
}

void imprime(float **matriz, int linha, int coluna){
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            printf("Matriz[%d][%d] = %.2f\n", i, j, matriz[i][j]);
        }
    }
}

void desaloca(float **matriz, int linha){
    for(int i = 0; i < linha; i++){
        free(matriz[i]);
    }
    free(matriz);
}

int main(){
    int exer;
    printf("Insira o numero de exercicio que deseja acessar:\n");
    while(1) {
        scanf(" %d", &exer);
        if(exer == 1) { //Exercício 1:
            float peso, altura, res;
            printf("Insira o seu peso em kg: \n");
            scanf(" %f", &peso);
            printf("Insira a sua altura em metros: \n");
            scanf(" %f", &altura);

            res = imc(peso, altura);

            printf("IMC: %.2f\n", res);
            break;
        }else if(exer == 2) {//Exercício 2:
            int n, res;
            printf("Insira o valor de N: \n");
            scanf(" %d", &n);

            res = somatorio(n);

            printf("Somatorio: %d\n", res);
            break;
        }else if(exer == 3) {//Exercício 3:
            printf("Decrescente:\n");
            decrescente(15);

            printf("Crescente:\n");
            crescente(15);
            break;
        }else if(exer == 4) {//Exercício 4:
            float **A = aloca(2, 3);
            leitura(A, 2, 3);
            float **B = aloca(3, 2);
            leitura(B, 3, 2);
            float **C = multiplica(A, 2, 3, B, 3, 2);

            imprime(A, 2, 3);
            printf("=====================================================\n");
            imprime(B, 3, 2);
            printf("=====================================================\n");
            imprime(C, 2, 2);

            desaloca(A, 2);
            desaloca(B, 3);
            desaloca(C, 2);
            break;
        }else if(exer == 5) {//Exercício 5:
            float tempoit, temporec;
            time_t inicio, fim;

            printf("Fibonacci Iterativo:\n");
            inicio = time(NULL);
            for (int i = 1; i < 100; i++) {
                printf("Termo %d: %lld\n", i, fibit(i));
            }
            fim = time(NULL);
            tempoit = difftime(fim, inicio);
            printf("Tempo de execucao: %f\n", tempoit);


            printf("Fibonacci Recursivo:\n");
            inicio = time(NULL);
            for (int i = 1; i < 100; i++) {
                printf("Termo %d: %lld\n", i, fibrec(i));
            }
            fim = time(NULL);
            temporec = difftime(fim, inicio);
            printf("Tempo de execucao: %f\n", temporec);
            break;
        }else{
            printf("Exercicio nao encontrado, tente novamente.\n");
        }
    }
    return 0;
}