#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int exer;
    printf("Insira o numero do exercicio que deseja acessar:\n");
    while(1){
        scanf(" %d", &exer);

        if(exer == 1){
            int l1, c1, l2, c2;
            printf("Digite o numero de linhas da Matriz1:\n");
            scanf(" %d", &l1);
            printf("Digite o numero de colunas da Matriz1:\n");
            scanf(" %d", &c1);
            printf("Digite o numero de linhas da Matriz2:\n");
            scanf(" %d", &l2);
            printf("Digite o numero de colunas da Matriz2:\n");
            scanf(" %d", &c2);

            if (l1 != c2 || c1 != l2) {
                printf("Essas matrizes são imcompativeis.\n");
            }else{
                float matriz1[l1][c1], matriz2[l2][c2], matriz3[l1][c2], soma;

                for (int i = 0; i < l1; i++) {
                    for (int j = 0; j < c1; j++) {
                        printf("Matriz1[%d][%d]= \n", i, j);
                        scanf(" %f", &matriz1[i][j]);
                    }
                }

                for (int i = 0; i < l2; i++) {
                    for (int j = 0; j < c2; j++) {
                        printf("Matriz2[%d][%d]= \n", i, j);
                        scanf(" %f", &matriz2[i][j]);
                    }
                }

                for (int i = 0; i < l1; i++) {
                    for (int j = 0; j < c2; j++) {
                        soma = 0;
                        for (int k = 0; k < l2; k++) {
                            soma += matriz1[i][k] * matriz2[k][j];
                        }
                        matriz3[i][j] = soma;
                    }
                }

                for (int i = 0; i < l1; i++) {
                    for (int j = 0; j < c2; j++) {
                        printf("Matriz3[%d][%d]= %.1f\n", i, j, matriz3[i][j]);
                    }
                }
            }

            break;
        }else if(exer == 2){
            float notas[10][3], aluno[10][2], maiortotal = -1;
            int contador[4] = {0, 0, 0, 0};

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 3; j++){
                    printf("Insira a nota do aluno %d, na prova %d:\n", (i + 1), (j + 1));
                    scanf(" %f", &notas[i][j]);
                }
            }

            //Procurando a maior nota e analisando quantos alunos tiraram tal nota.
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 3; j++){
                    if(notas[i][j] > maiortotal){
                        maiortotal = notas[i][j];
                    }
                }
            }

            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 3; j++){
                    if(notas[i][j] == maiortotal){
                        contador[0] += 1;
                    }
                }
            }

            // Separando as melhoras notas na coluna 0 e a prova na coluna 1.
            for(int i = 0; i < 10; i++){
                aluno[i][0] = (float)-1;
                for(int j = 0; j < 3; j++){
                    if(notas[i][j] > aluno[i][0]){
                        aluno[i][0] = notas[i][j];
                        aluno[i][1] = (float)j + 1;
                    }
                }
            }

            for(int i = 0; i < 10; i++){
                if(aluno[i][1] == 1){
                    contador[1] += 1;
                }else if(aluno[i][1] == 2){
                    contador[2] += 1;
                }else{
                    contador[3] += 1;
                }
            }


            printf("A maior nota foi %.1f, obtida por %d alunos.\n", maiortotal, contador[0]);
            printf("Numero de alunos cuja melhor nota foi na prova 1: %d\n", contador[1]);
            printf("Numero de alunos cuja melhor nota foi na prova 2: %d\n", contador[2]);
            printf("Numero de alunos cuja melhor nota foi na prova 3: %d\n", contador[3]);

            break;
        }else if(exer == 3){
            int matriz[6][6], soma = 0;

            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 6; j++){
                    printf("Matriz[%d][%d]=\n", i, j);
                    scanf(" %d", &matriz[i][j]);
                    if(i > j){
                        soma += matriz[i][j];
                    }
                }
            }

            printf("A soma dos elementos abaixo da diagonal principal e igual a %d.\n", soma);

            break;
        }else if(exer == 4){
            #define TAM 2
            int matriz1[TAM][TAM], matriz2[TAM][TAM], matriz3[TAM][TAM];

            for(int i = 0; i < TAM; i++){
                for(int j = 0; j < TAM; j++){
                    matriz1[i][j] = 3*(i + 1) + 4*(j + 1);
                    matriz2[i][j] = -4*(i+1) + -3*(j + 1);
                }
            }

            for(int i = 0; i < TAM; i++){
                for(int j = 0; j < TAM; j++){
                    matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
                }
            }

            printf("===Matriz 1===\n");
            for(int i = 0; i < TAM; i++){
                for(int j = 0; j < TAM; j++){
                    printf("%d\n", matriz1[i][j]);
                }
            }

            printf("===Matriz 2===\n");
            for(int i = 0; i < TAM; i++){
                for(int j = 0; j < TAM; j++){
                    printf("%d\n", matriz2[i][j]);
                }
            }

            printf("===Matriz 3===\n");
            for(int i = 0; i < TAM; i++){
                for(int j = 0; j < TAM; j++){
                    printf("%d\n", matriz3[i][j]);
                }
            }

            break;
        }else if(exer == 5){
            int p, q;

            printf("Insira o numero de linhas da Matriz:\n");
            scanf(" %d", &p);
            printf("Insira o numero de colunas da Matriz:\n");
            scanf(" %d", &q);

            int matriz[p][q], vetor1[p], vetor2[q], soma;

            for(int i = 0; i < p; i++){
                for(int j = 0; j < q; j++){
                    printf("Matriz[%d][%d]=\n", i, j);
                    scanf(" %d", &matriz[i][j]);
                }
            }

            for(int i = 0; i < p; i++){
                soma = 0;
                for(int j = 0; j < q; j++){
                    soma += matriz[i][j];
                }
                vetor1[i] = soma;
            }

            for(int i = 0; i < q; i++){
                soma = 0;
                for(int j = 0; j < p; j++){
                    soma += matriz[j][i];
                }
                vetor2[i] = soma;
            }

            printf("===Somatorio das Linhas===\n");
            for(int i = 0; i < p; i++){
                printf("Linha[%d] = %d\n", i, vetor1[i]);
            }

            printf("===Somatorio das Colunas===\n");
            for(int i = 0; i < q; i++){
                printf("Coluna[%d] = %d\n", i, vetor2[i]);
            }

            break;
        }else{
            printf("Exercicio nao encontrado, tente novamente.\n");
        }
    }
}
