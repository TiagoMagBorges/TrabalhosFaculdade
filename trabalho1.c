#include <stdio.h>
#include <stdlib.h>

// Funções auxiliares.

void imprimevetorint(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
}

void imprimevetorfloat(float *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Vetor[%d]: %.2f\n", i, vetor[i]);
    }
}

void recebevetorint(int *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Insira um valor para Vetor[%d]:\n", i);
        scanf(" %d", &vetor[i]);
    }
}

void recebevetorfloat(float *vetor, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Insira um valor para Vetor[%d]:\n", i);
        scanf(" %f", &vetor[i]);
    }
}

int main(){
    int exer;
    printf("Insira o numero da atividade que voce deseja acessar:\n");

    while(1){
        scanf(" %d", &exer);

        if(exer == 1){ // Exercício 1.

            int qtd, tipo;
            float matriz[4][3] = {{170.00, 151.30, 139.20},
                                  {153.20, 136.17, 125.28},
                                  {139.23, 123.91, 112.76},
                                  {128.09, 117.84, 104.88}};

            do{
                printf("Insira a quantidade de quebrados (3, 4 ou 5): \n");
                scanf(" %d", &qtd);
            }while(qtd < 3 || qtd > 5);
            qtd -= 3;

            do{
                printf("Para escolher o tipo A, digite 1.\nPara escolher o tipo B, digite 2.\nPara escolher o tipo C, digite 3.\nPara escolher o tipo D, digite 4.\n");
                scanf(" %d", &tipo);
            }while(tipo < 1 || tipo > 4);
            tipo -= 1;

            printf("O valor e de R$%.2f.", matriz[tipo][qtd]);

            break;

        }else if(exer == 2){ // Exercício 2.

            #define TAM 10
            int vetor[TAM], num, alerta = 0;

            for(int i = 0; i < TAM; i++){
                printf("Insira um valor para Vetor[%d]: \n", i);
                scanf(" %d", &num);

                for(int j = 0; j < i; j++){
                    if(vetor[j] == num){
                        alerta = 1;
                        break;
                    }
                }

                if(alerta == 1){
                    printf("Numero repetido, tente novamente.\n");
                    --i;
                    alerta = 0;
                }else{
                    vetor[i] = num;
                }
            }

            imprimevetorint(vetor, TAM);

            break;

        }else if(exer == 3){ // Exercício 3.
            float vetor[20];

            recebevetorfloat(vetor, 20);

            for(int i = 0; i < 20; i++){
                for(int j = i + 1; j < 20; j++){
                    if(vetor[i] > vetor[j]){
                        float aux = vetor[i];
                        vetor[i] = vetor[j];
                        vetor[j] = aux;
                    }
                }
            }

            imprimevetorfloat(vetor, 20);

            break;

        }else if(exer == 4){ // Exercício 4.
            int tam;

            printf("Insira o tamanho do vetor:\n");
            scanf(" %d", &tam);

            float soma = 0, vetor[tam];

            recebevetorfloat(vetor, tam);

            for(int i = 0; i < tam; i++){
                soma += ((float)i + 1) / vetor[i];
            }

            printf("%f", soma);

            break;

        }else if(exer == 5){
            float media = 0, desvio;
            int tam;

            printf("Insira o tamanho do vetor:\n");
            scanf(" %d", &tam);

            float vetor[tam];

            for(int i = 0; i < tam; i++){
                printf("Insira um valor:\n");
                scanf(" %f", &vetor[i]);
                media += vetor[i];
            }

            media = media / (float)tam;

            for(int i = 0; i < tam; i++){
                desvio = vetor[i] - media;
                printf("O desvio padrao do vetor[%d] e de %.1f.\n", i, desvio);
            }

            break;

        }else{
            printf("O exercicio %d nao foi encontrado, tente novamente.\n", exer);
        }
    }
}
