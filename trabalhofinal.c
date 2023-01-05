/*
    Este programa implementa structs Horario (armazenamento do horario de entrada e saida de um Carro em uma determinada
garagem) e Carro (armazenamento de detalhes do Carro), visando um controle de entrada e saida de veiculos, armazenando-os
em um arquivo binario.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    * Definicao da estrutura de dados Horario.
    * - 5 inteiros representando ano, mes, dia, hora e minuto.
*/
struct horario{
    int ano, mes, dia, hora, min;
};

// Definindo o TIPO Horario
typedef struct horario Horario;

/*
    * Definicao da estrutura de dados Carro.
    * - 3 vetores de char representando placa, modelo e cor do carro.
    * - 1 char representando o status de permanencia do carro (Presente/Removido).
    * - 2 Horario representando o horario de entrada e saida do carro.
*/
struct carro{
    char placa[8], modelo[10], cor[10], status;Horario inicio, fim;
};

// Definindo o TIPO Carro
typedef struct carro Carro;

void validahorarioentrada(Carro *x);
void validahorariosaida(Carro *x);
void inserir(FILE *arquivo);
void listar(FILE *arquivo);
void buscar(FILE *arquivo);
void alterar(FILE *arquivo);
void remover(FILE *arquivo);
void tempo(Carro *x, int *resultado);

int main(){
    // Abertura do arquivo para leitura e/ou escrita.
    FILE *arquivo = fopen("arquivo.txt", "rb+");
    if (arquivo == NULL) {
        arquivo = fopen("arquivo.txt", "wb+");
        if (arquivo == NULL) {
            printf("Nao foi possivel abrir o arquivo.\n");
            exit(1);
        }
    }

    // Menu de opcoes.
    int opcao;
    do{
        printf("====================\n"
               "0- Sair.\n"
               "1- Inserir.\n"
               "2- Alterar.\n"
               "3- Remover.\n"
               "4- Buscar.\n"
               "5- Listar.\n"
               "====================\n"
               "Opcao: \n");
        scanf(" %d", &opcao);
        switch (opcao){
            case 1: inserir(arquivo); break;
            case 2: alterar(arquivo); break;
            case 3: remover(arquivo); break;
            case 4: buscar(arquivo); break;
            case 5: listar(arquivo); break;
        }
    }while(opcao != 0);

    // Fechando o arquivo.
    fclose(arquivo);

    return 0;
}

/*
    * Nome: validahorarioentrada
    * Entrada: 1 ponteiro de Carro
    * Processo: armazena na struct Carro -> Horario -> inicio o horario de entrada do veiculo na garagem, verificando se
    os dados inseridos correspondem com os padrões de ano, mes, dia, hora e minuto.
    * Saida: o horario->inicio inserido, já formatado.
*/
void validahorarioentrada(Carro *x){
    int bissexto = 0;
    printf("====================\n"
           "Informacoes sobre data e hora.\n");
    printf("Ano: \n");
    scanf(" %d", &x->inicio.ano);
    if ((x->inicio.ano % 400 == 0) || ((x->inicio.ano % 4 == 0) && (x->inicio.ano % 100 != 0))) {
        bissexto = 1;
    }
    printf("Mes: \n");
    while(1){
        scanf(" %d", &x->inicio.mes);
        if(x->inicio.mes < 0 || x->inicio.mes > 12){
            printf("Mes invalido, tente novamente.\n");
        }else if (x->inicio.mes == 1 || x->inicio.mes == 3 || x->inicio.mes == 5 || x->inicio.mes == 7 || x->inicio.mes == 8 || x->inicio.mes == 10 || x->inicio.mes == 12){
            printf("Dia: \n");
            while(1){
                scanf(" %d", &x->inicio.dia);
                if(x->inicio.dia > 0 && x->inicio.dia <= 31){
                    break;
                }else{
                    printf("Dia invalido, tente novamente.\n");
                }
            }
            break;
        }else if(x->inicio.mes == 4 || x->inicio.mes == 6 || x->inicio.mes == 9 || x->inicio.mes == 11){
            printf("Dia: \n");
            while(1){
                scanf(" %d", &x->inicio.dia);
                if(x->inicio.dia > 0 && x->inicio.dia <= 30){
                    break;
                }else{
                    printf("Dia invalido, tente novamente.\n");
                }
            }
            break;
        }else if(x->inicio.mes == 2){
            if(bissexto == 1){
                printf("Dia: \n");
                while(1){
                    scanf(" %d", &x->inicio.dia);
                    if(x->inicio.dia > 0 && x->inicio.dia <= 29){
                        break;
                    }else{
                        printf("Dia invalido, tente novamente.\n");
                    }
                }
            }else{
                printf("Dia: \n");
                while (1) {
                    scanf(" %d", &x->inicio.dia);
                    if (x->inicio.dia > 0 && x->inicio.dia <= 28){
                        break;
                    } else {
                        printf("Dia invalido, tente novamente.\n");
                    }
                }
            }
            break;
        }else{
            printf("Mes invalido, tente novamente.\n");
        }
    }
    printf("Hora: \n");
    while(1){
        scanf(" %d", &x->inicio.hora);
        if(x->inicio.hora >= 0 && x->inicio.hora < 24){
            break;
        }else{
            printf("Hora invalida, tente novamente.\n");
        }
    }
    printf("Minuto: \n");
    while(1){
        scanf(" %d", &x->inicio.min);
        if(x->inicio.min >= 0 && x->inicio.min <= 59){
            break;
        }else{
            printf("Minuto invalido, tente novamente.\n");
        }
    }
}

/*
    * Nome: validahorariosaida
    * Entrada: 1 ponteiro de Carro
    * Processo: armazena na struct Carro -> Horario -> fim o horario de saido do veiculo da garagem, verificando se
    os dados inseridos correspondem com os padrões de ano, mes, dia, hora e minuto.
    * Saida: o horario->fiminserido, já formatado.
*/
void validahorariosaida(Carro *x) {
    int bissexto = 0;
    printf("====================\n"
           "Informacoes sobre data e hora.\n");
    printf("Ano: \n");
    scanf(" %d", &x->fim.ano);
    if ((x->fim.ano % 400 == 0) || ((x->fim.ano % 4 == 0) && (x->fim.ano % 100 != 0))) {
        bissexto = 1;
    }
    printf("Mes: \n");
    while (1) {
        scanf(" %d", &x->fim.mes);
        if(x->fim.mes < 0 || x->fim.mes > 12){
            printf("Mes invalido, tente novamente.\n");
        }else if(x->fim.mes == 1 || x->fim.mes == 3 || x->fim.mes == 5 || x->fim.mes == 7 || x->fim.mes == 8 || x->fim.mes == 10 || x->fim.mes == 12){
            printf("Dia: \n");
            while (1) {
                scanf(" %d", &x->fim.dia);
                if(x->fim.dia > 0 && x->fim.dia <= 31){
                    break;
                }else{
                    printf("Dia invalido, tente novamente.\n");
                }
            }
            break;
        }else if(x->fim.mes == 4 || x->fim.mes == 6 || x->fim.mes == 9 || x->fim.mes == 11){
            printf("Dia: \n");
            while (1) {
                scanf(" %d", &x->fim.dia);
                if (x->fim.dia > 0 && x->fim.dia <= 30) {
                    break;
                } else {
                    printf("Dia invalido, tente novamente.\n");
                }
            }
            break;
        } else if (x->fim.mes == 2) {
            if (bissexto == 1) {
                printf("Dia: \n");
                while (1) {
                    scanf(" %d", &x->fim.dia);
                    if (x->fim.dia > 0 && x->fim.dia <= 29) {
                        break;
                    } else {
                        printf("Dia invalido, tente novamente.\n");
                    }
                }
            } else {
                printf("Dia: \n");
                while (1) {
                    scanf(" %d", &x->fim.dia);
                    if (x->fim.dia > 0 && x->fim.dia <= 28) {
                        break;
                    } else {
                        printf("Dia invalido, tente novamente.\n");
                    }
                }
            }
            break;
        } else {
            printf("Mes invalido, tente novamente.\n");
        }
    }
    printf("Hora: \n");
    while (1) {
        scanf(" %d", &x->fim.hora);
        if (x->fim.hora >= 0 && x->fim.hora < 24) {
            break;
        } else {
            printf("Hora invalida, tente novamente.\n");
        }
    }
    printf("Minuto: \n");
    while (1) {
        scanf(" %d", &x->fim.min);
        if (x->fim.min >= 0 && x->fim.min <= 59) {
            break;
        } else {
            printf("Minuto invalido, tente novamente.\n");
        }
    }
}

/*
    * Nome: inserir
    * Entrada: 1 ponteiro de arquivo FILE.
    * Processo: Cria um ponteiro de Carro e recebe todos os dados da struct, em seguida, os armazena no arquivo FILE.
    * Saida: Escreve no arquivo FILE a struct Carro.
*/
void inserir(FILE *arquivo){
    rewind(arquivo);
    Carro *x = (Carro*) malloc(1* sizeof(Carro));
    printf("====================\n"
           "Informacoes sobre o veiculo.\n");
    printf("Placa: \n");
    fflush(stdin);
    gets(x->placa);fflush(stdin);
    printf("Modelo: \n");
    gets(x->modelo);fflush(stdin);
    printf("Cor: \n");
    gets(x->cor);fflush(stdin);
    validahorarioentrada(x);
    x->status = 'P';
    fseek(arquivo, 0, SEEK_END);
    fwrite(x, sizeof(Carro), 1, arquivo);
    printf("Registrado com sucesso, retornando ao Menu.\n");

}

/*
    * Nome: listar
    * Entrada: 1 ponteiro de arquivo FILE.
    * Processo: Le todos os Carros armazenados no arquivo que em que o status e 'P'.
    * Saida: Imprime todos os Carros com status 'P' (presente).
*/
void listar(FILE *arquivo){
    rewind(arquivo);
    Carro *x = (Carro*) malloc(sizeof(Carro));
    while(fread(x, sizeof(Carro), 1, arquivo) == 1){
        if(x->status == 'P'){
            printf("====================\n"
                   "Placa: %s\n"
                   "Modelo: %s\n"
                   "Cor: %s\n"
                   "Data e hora: %.2d/%.2d/%.4d %.2d:%.2d\n"
                   "====================\n", x->placa, x->modelo, x->cor, x->inicio.dia, x->inicio.mes, x->inicio.ano, x->inicio.hora, x->inicio.min);
        }
    }
    free(x);
}

/*
    * Nome: buscar
    * Entrada: 1 ponteiro de arquivo FILE.
    * Processo: Busca no arquivo FILE um Carro, tendo como chave, a placa.
    * Saida: Imprime o Carro, caso encontrado.
*/
void buscar(FILE *arquivo){
    rewind(arquivo);
    char placa[8];
    Carro *x = (Carro*) malloc(sizeof(Carro));
    printf("Digite a placa do veiculo: \n");
    gets(placa);fflush(stdin);
    while(fread(x, sizeof(Carro), 1, arquivo) == 1){
        if(strcmp(placa, x->placa) == 0 && x->status == 'P'){
            printf("====================\n"
                   "Placa: %s\n"
                   "Modelo: %s\n"
                   "Cor: %s\n"
                   "Data e hora: %.2d/%.2d/%.4d %.2d:%.2d\n"
                   "====================\n", x->placa, x->modelo, x->cor ,x->inicio.dia, x->inicio.mes, x->inicio.ano, x->inicio.hora, x->inicio.min);
        }
    }
    free(x);
}

/*
    * Nome: alterar
    * Entrada: 1 ponteiro de arquivo FILE.
    * Processo: Busca no arquivo FILE um Carro, tendo como chave, a placa, e em seguida apresenta um menu que permite a
    alteracao de dados do registro.
    * Saida: Sobrescreve a struct Carro no arquivo com os dados atualizados.
*/
void alterar(FILE *arquivo){
    rewind(arquivo);
    int posicao;
    char placa[8];
    Carro *x = (Carro*) malloc(sizeof(Carro));
    printf("Digite a placa do veiculo a ser alterado: \n");
    gets(placa);fflush(stdin);
    while(fread(x, sizeof(Carro), 1, arquivo) == 1){
        if(strcmp(placa, x->placa) == 0 && x->status == 'P'){
            printf("====================\n"
                   "Placa: %s\n"
                   "Modelo: %s\n"
                   "Cor: %s\n"
                   "Data e hora: %.2d/%.2d/%.4d %.2d:%.2d\n"
                   "====================\n", x->placa, x->modelo, x->cor ,x->inicio.dia, x->inicio.mes, x->inicio.ano, x->inicio.hora, x->inicio.min);
            int op;
            do{
                printf("====================\n"
                       "O que vai ser alterado?\n"
                       "0- Sair.\n"
                       "1- Placa.\n"
                       "2- Modelo.\n"
                       "3- Cor.\n"
                       "====================\n"
                       "Opcao: \n");
                scanf(" %d", &op);
                switch (op){
                    case 1: printf("Placa antiga: %s\nPlaca atual: ", x->placa);gets(x->placa);fflush(stdin);break;
                    case 2: printf("Modelo antigo: %s\nModelo atual: ", x->modelo);gets(x->modelo);fflush(stdin);break;
                    case 3: printf("Cor antiga: %s\nCor atual: ", x->cor);gets(x->cor);fflush(stdin);break;
                }
            }while(op != 0);
            posicao = ftell(arquivo) - sizeof(Carro);
            rewind(arquivo);
            fseek(arquivo, posicao, SEEK_SET);
            fwrite(x, sizeof(Carro), 1, arquivo);
            free(x);
            printf("Alterado com sucesso, retornando ao menu.\n");
            break;
        }
    }
}

/*
    * Nome: remover
    * Entrada: 1 ponteiro de arquivo FILE.
    * Processo: Busca no arquivo FILE um Carro, tendo como chave, a placa, e em seguida pede ao usuario inserir a data e
    horario de saida, e altera altomaticamente o status de 'P' para 'R'.
    * Saida: Sobrescreve a struct Carro no arquivo com os dados atualizados.
*/
void remover(FILE *arquivo){
    rewind(arquivo);
    int posicao, *res = (int*) malloc(2* sizeof(int));
    char placa[8];
    Carro *x = (Carro*) malloc(1* sizeof(Carro));
    printf("Digite a placa do veiculo a ser removido: \n");
    gets(placa);
    while(fread(x, sizeof(Carro), 1, arquivo) == 1){
        if(strcmp(placa, x->placa) == 0 && x->status == 'P'){
            printf("====================\n"
                   "Placa: %s\n"
                   "Modelo: %s\n"
                   "Cor: %s\n"
                   "Data e hora: %.2d/%.2d/%.4d %.2d:%.2d\n"
                   "====================\n", x->placa, x->modelo, x->cor ,x->inicio.dia, x->inicio.mes, x->inicio.ano, x->inicio.hora, x->inicio.min);
            printf("Insira a data e horario de saida: \n");
            validahorariosaida(x);
            tempo(x, res);
            printf("Tempo de permanencia: %d horas e %d minutos.\n", res[0], res[1]);
            x->status = 'R';
            posicao = ftell(arquivo) - sizeof(Carro);
            rewind(arquivo);
            fseek(arquivo, posicao, SEEK_SET);
            fwrite(x, sizeof(Carro), 1, arquivo);
            printf("Removido com sucesso, retornando ao menu.\n");
            break;
        }
    }
}

/*
    * Nome: Tempo
    * Entrada: Um ponteiro de registro e um ponteiro de um vetor de duas posicoes representando as horas e os minutos.
    * Processo: Compara e calcula a diferenca em horas e minutos de permanencia do Carro.
    * Saida: As horas na posicao 0 e os minutos na posicao 1
*/
void tempo(Carro *x, int *resultado){
    int bissexto = 0, hora = 0, contamin = 0;
    Horario aux;
    aux.ano = x->inicio.ano;
    aux.mes = x->inicio.mes;
    aux.dia = x->inicio.dia;
    aux.hora = x->inicio.hora;
    aux.min = x->inicio.min;
    while(1){
        if ((aux.ano % 400 == 0) || ((aux.ano % 4 == 0) && (aux.ano % 100 != 0))){
            bissexto = 1;
        }
        if(contamin == 60){
            hora += 1;
            contamin = 0;
        }
        if(aux.min == 60){
            aux.hora += 1;
            aux.min = 0;
        }
        if(aux.hora == 24){
            aux.dia += 1;
            aux.hora = 0;
            hora += 1;
        }
        if(aux.mes == 13){
            aux.ano += 1;
            aux.mes = 1;
        }
        if(aux.mes == 1 || aux.mes == 3 || aux.mes == 5 || aux.mes == 7 || aux.mes == 8 || aux.mes == 10 || aux.mes == 12){
            if(aux.dia == 32){
                aux.mes += 1;
                aux.dia = 1;
            }
        }else if (aux.mes == 4 || aux.mes == 6 || aux.mes == 9 || aux.mes == 11){
            if(aux.dia == 31){
                aux.mes += 1;
                aux.dia = 1;
            }
        }else if (aux.mes == 2 && bissexto == 0){
            if(aux.dia == 29){
                aux.mes += 1;
                aux.dia = 1;
            }
        }else if (aux.mes == 2 && bissexto == 1) {
            if (aux.dia == 30) {
                aux.mes += 1;
                aux.dia = 1;
            }
        }
        if(aux.ano == x->fim.ano && aux.mes == x->fim.mes && aux.dia == x->fim.dia && aux.hora == x->fim.hora && aux.min == x->fim.min){
            break;
        }else {
            aux.min += 1;
            contamin += 1;
        }
    }
    resultado[0] = hora;
    resultado[1] = contamin;
}
