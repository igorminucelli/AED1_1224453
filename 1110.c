/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Igor Aparecido Minucelli Pinto>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 21/09/2026
Objetivo    : Mover a carta a do topo para baixo e encontrar a sequência de cartas descartadas.
Dificuldade : <<<Entender como funciona os descartes>>>
Uso de IA   : <<<Usei para entender como por em pratica o uso das filas>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

/*Criei o nó da lista*/
typedef struct noh{
    int valor;
    struct noh* seguinte;
}noh;

/*Aqui é a estrutura da fila*/
typedef struct{
    noh* cab;
    noh* rabo;
    int tam;
}fila;

/*Aqui é uma função feita para iniciar a fila*/
void iniFila(fila *f){
    /*f é o ponteiro que aponta para a cabeça e para o rabo*/
    f -> cab = NULL;
    f -> rabo = NULL;
}

/*Aqui vamos colocar um elemento no final da fila, fazendo o elemento apontar para o valor e o próximo*/
void cricaixa(fila *f, int valor){
    noh *nohnovo = (noh *)malloc(sizeof(noh));
    nohnovo -> valor = valor;
    nohnovo -> seguinte = NULL; 

    /*Aqui ele olha se o rabo tem algum valor, se tiver ele passa para o próximo*/
    if(f -> rabo == NULL){
        f -> cab = nohnovo;
        f -> rabo = nohnovo;
    }
    else{ 
        f -> rabo -> seguinte = nohnovo;
        f -> rabo = nohnovo;
    }
}

/*Função para voltar o elemento para o começo da fila*/
int voltar(fila *f){
    if(f -> cab == NULL){
        return -1;
    }
    noh *temp = f -> cab;
    int valor = temp -> valor;

    f -> cab = f -> cab -> seguinte;
    if(f -> cab == NULL){
        f -> rabo = NULL;
    }

    /*Liberar a variável temp*/
    free(temp);
    return valor;
}

/*Liberar o espaço de memória do resto*/
void limp(fila *f){
    while(f -> cab != NULL){
        voltar(f);
    }
}

int main(){
    int n;

    while (scanf("%d", &n) == 1 && n != 0) {
        fila baralho;
        iniFila(&baralho);

        /*coloca os valores de 1 até n das cartas na fila*/
        for (int i = 1; i <= n; i++) {
            cricaixa(&baralho, i);
        }

        printf("Discarded cards:");

        int primeiroDescarte = 1;

        while (baralho.cab != baralho.rabo) {
            /*Descarta o topo da fila*/
            int descartada = voltar(&baralho);
            
            if (primeiroDescarte) {
                printf(" %d", descartada);
                primeiroDescarte = 0;
            } else {
                printf(", %d", descartada);
            }

            int mover = voltar(&baralho);
            cricaixa(&baralho, mover);
        }
        int restante = voltar(&baralho);
        printf("\nRemaining card: %d\n", restante);
    }

    return 0;
}
