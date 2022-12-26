#include <stdio.h>
#include <stdlib.h>


int main(){
    int exer;
    printf("Insira o exercicio que deseja acessar:\n");
    while(1){
        scanf(" %d", &exer);
        if(exer == 1){
            int l1, c1, l2, c2;

            // Recebendo o tamanho das Matrizes e checando se são compatíveis.
            while(1){
                printf("Insira o numero de linhas da Matriz1:\n");
                scanf(" %d", &l1);
                printf("Insira o numero de colunas da Matriz1:\n");
                scanf(" %d", &c1);
                printf("Insira o numero de linhas da Matriz2:\n");
                scanf(" %d", &l2);
                printf("Insira o numero de colunas da Matriz2:\n");
                scanf(" %d", &c2);

                if(l1 != c2){
                    printf("As matrizes nao sao compativeis, tente novamente.\n");
                }else{
                    break;
                }
            }

            // Declarando as Matrizes.
            float **matriz1 = (float**) malloc(l1*sizeof(float*));
            for(int i = 0; i < l1; i++){
                matriz1[i] = (float*) malloc(c1* sizeof(float));
            }

            float **matriz2 = (float**) malloc(l2*sizeof(float*));
            for(int i = 0; i < l2; i++){
                matriz2[i] = (float*) malloc(c2* sizeof(float));
            }

            float **matriz3 = (float**) malloc(l1*sizeof(float*));
            for(int i = 0; i < l1; i++){
                matriz3[i] = (float*) malloc(c2* sizeof(float));
            }

            // Recebendo os valores das Matrizes.
            for(int i = 0; i < l1; i++){
                for(int j = 0; j < c1; j++){
                    printf("Insira o valor para Matriz1[%d][%d]:\n", i, j);
                    scanf(" %f", &matriz1[i][j]);
                }
            }

            for(int i = 0; i < l2; i++){
                for(int j = 0; j < c2; j++){
                    printf("Insira o valor para Matriz2[%d][%d]:\n", i, j);
                    scanf(" %f", &matriz2[i][j]);
                }
            }

            // Calculando a multiplicação das duas Matrizes.
            float soma;
            for (int i = 0; i < l1; i++) {
                for (int j = 0; j < c2; j++) {
                    soma = 0;
                    for (int k = 0; k < l2; k++) {
                        soma += matriz1[i][k] * matriz2[k][j];
                    }
                    matriz3[i][j] = soma;
                }
            }

            // Retornando o resultado.
            for(int i = 0; i < l1; i++){
                for(int j = 0; j < c2; j++){
                    printf("Matriz3[%d][%d]= %.1f.\n", i, j, matriz3[i][j]);
                }
            }

            // Desalocando as matrizes.
            for(int i = 0; i < l1; i++){
                free(matriz1[i]);
            }
            free(matriz1);

            for(int i = 0; i < l2; i++){
                free(matriz2[i]);
            }
            free(matriz2);

            for(int i = 0; i < l1; i++){
                free(matriz3[i]);
            }
            free(matriz3);

            break;
        }else if(exer == 2){
            // Declarando a Matriz.
            float **matriz = (float**) malloc(5* sizeof(float*));
            for(int i = 0; i < 5; i++){
                matriz[i] = (float*) malloc(5* sizeof(float));
            }

            // Recebendo os valores da Matriz.
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    printf("Insira o valor para Matriz[%d][%d]:\n", i, j);
                    scanf(" %f", &matriz[i][j]);
                }
            }

            // Recebendo o valor a ser procurado.
            float valor;
            int contador = 0;
            while(1){
                printf("Insira o valor que deseja procurar, caso deseje encerrar a busca, digite 0.\n");
                scanf(" %f", &valor);
                if(valor == 0){
                    break;
                }else{
                    // Vendo quantas vezes esse numero aparece na matriz.
                    for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 5; j++){
                            if(valor == matriz[i][j]){
                                contador++;
                            }
                        }
                    }
                    // Salvando as posições em que ele foi encontrado.
                    int posicoes[contador*2], controle = 0;
                    for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 5; j++){
                            if(valor == matriz[i][j]){
                                posicoes[controle++] = i;
                                posicoes[controle++] = j;
                            }
                        }
                    }

                    // Retornando as posições encontradas.
                    if(contador > 0) {
                        printf("O numero %.2f foi encontrado nas posicoes:\n", valor);
                        controle = 0;
                        for (int i = 0; i < contador; i++) {
                            printf("Matriz[%d", posicoes[controle++]);
                            printf("][%d]\n", posicoes[controle++]);
                        }
                    }else{
                        printf("Valor nao encontrado.\n");
                    }

                    controle = 0;
                    contador = 0;
                }
            }

            // Desalocando a Matriz.
            for(int i = 0; i < 5; i++){
                free(matriz[i]);
            }
            free(matriz);

            printf("Isso e tudo, pessoal!\n");

            break;
        }else if(exer == 3){
            // Declarando a Matriz.
            float **matriz = (float**) malloc(5* sizeof(float*));
            for(int i = 0; i < 5; i++){
                matriz[i] = (float*) malloc(5* sizeof(float));
            }

            // Recebendo os valores da Matriz.
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++){
                    printf("Insira o valor para Matriz[%d][%d]:\n", i, j);
                    scanf(" %f", &matriz[i][j]);
                }
            }

            // Recebendo o valor a ser procurado.
            float valor;
            int contador = 0;
            while(1){
                printf("Insira o valor que deseja procurar, caso deseje encerrar a busca, digite 0.\n");
                scanf(" %f", &valor);
                if(valor == 0){
                    break;
                }else{
                    // Vendo quantas vezes esse numero aparece na matriz.
                    for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 5; j++){
                            if(valor == matriz[i][j]){
                                contador++;
                            }
                        }
                    }
                    // Salvando as posições em que ele foi encontrado.
                    int posicoes[contador*2], controle = 0;
                    for(int i = 0; i < 5; i++){
                        for(int j = 0; j < 5; j++){
                            if(valor == matriz[i][j]){
                                posicoes[controle++] = i;
                                posicoes[controle++] = j;
                            }
                        }
                    }

                    // Retornando as posições encontradas.
                    if(contador > 0) {
                        printf("O numero %.2f foi encontrado nas posicoes:\n", valor);
                        controle = 0;
                        for (int i = 0; i < contador; i++) {
                            printf("Matriz[%d", posicoes[controle++]);
                            printf("][%d]\n", posicoes[controle++]);
                        }
                    }else{
                        printf("Valor nao encontrado.\n");
                    }
                    controle = 0;
                    contador = 0;
                }
            }

            // Desalocando a Matriz.
            for(int i = 0; i < 5; i++){
                free(matriz[i]);
            }
            free(matriz);

            printf("Isso e tudo, pessoal!\n");

            break;
        }else if(exer == 4){
            // Declarando a matriz.
            #define TAM 3
            int linha = TAM, coluna = TAM;
            int **matriz = (int**) malloc(linha* sizeof(int*));
            for(int i = 0; i < linha; i++){
                matriz[i] = (int*) malloc(coluna* sizeof(int));
            }

            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    printf("Insira o valor para Matriz[%d][%d]:\n", i, j);
                    scanf(" %d", &matriz[i][j]);
                }
            }

            // Calculando a determinante.
            int soma[6] = {1, 1, 1, 1, 1, 1}, res;
            for(linha = 0; linha < TAM; linha++){
                soma[0] *= matriz[linha][linha];
            }
            soma[1] *= matriz[0][1] * matriz[1][2] * matriz[2][0];
            soma[2] *= matriz[0][2] * matriz[1][0] * matriz[2][1];


            coluna = TAM - 1;
            for(linha = 0; linha < TAM; linha++){
                soma[3] *= matriz[linha][coluna];
                coluna--;
            }
            soma[4] *= matriz[0][0] * matriz[1][2] * matriz[2][1];
            soma[5] *= matriz[2][2] * matriz[1][0] * matriz[0][1];


            res = soma[0] + soma[1] + soma[2] - soma[3] - soma[4] - soma[5];

            // Retornando o resultado;
            printf("O resultado e igual a: %d.\n", res);

            // Desalocando a Matriz.
            for(int i = 0; i < TAM; i++){
                free(matriz[i]);
            }
            free(matriz);

            break;
        }else if(exer == 5){
            // Declarando a matriz.
            int linha = 7, coluna = 6, profundidade = 5;
            int ***matriz = (int***) malloc(linha* sizeof(int**));
            for(int i = 0; i < linha; i++){
                matriz[i] = (int**) malloc(coluna* sizeof(int*));
                for(int j = 0; j < coluna; j++){
                    matriz[i][j] = (int*) malloc(profundidade* sizeof(int));
                }
            }

            // Recebendo os valores da Matriz.
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    for(int k = 0; k < profundidade; k++){
                        matriz[i][j][k] = rand()%100+1;
                    }
                }
            }

            // Imprimindo a Matriz.
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    for(int k = 0; k < profundidade; k++){
                        printf("Matriz[%d][%d][%d] = %d.\n", i, j, k , matriz[i][j][k]);
                    }
                }
            }

            // Desalocando a Matriz
            for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++)
                    free(matriz[i][j]);
                free(matriz[i]);
            }
            free(matriz);

            break;
        }else{
            printf("Exercicio nao encontrado.\n");
        }
    }
}