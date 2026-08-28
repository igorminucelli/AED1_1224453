/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Igor Aparecido Minucelli Pinto>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1383>>
Data        : 27/08/2026
Objetivo    : Verificar se uma matriz 9x9 corresponde as regras do sudoku e usar alocação dinâmica.
Dificuldade : <<<A dificuldade foi usar a locação dinâmica, pois eu tive que criar um vetor de vetor e alocar os 9 números de cada linha >>>
Uso de IA   : <<<Usei para dizer onde estava o erro do meu código e me explicar de que modo eu poderia resolver, foi ai que ela me disse que faltava alocar os 9 números de cada linha>>>
-------------------------------------------------------------------------- */
#include<stdio.h>
#include<stdlib.h>

int sudoku[9][9];

/*Função que valida se o vetor de tamanho 9 possui números de 1 a 9 que são diferentes*/
int verificar(int num[9]){
    int ver[10] = {0};
    for(int i = 0; i < 9; i++){
        int valor = num[i];
        if(valor < 1 || valor >9 || ver[valor]){
            return 0;
        }
        ver[valor] = 1;
    }
    return 1;
}

int main(){
    int n;
    int **matriz;

    if(scanf("%d", &n) != 1){
        return 0;
    }

    for(int v = 0; v < n; v++){
        int blz = 1;

        /*Alocação dinamica da matriz*/
        matriz = ((int **)malloc(9 * sizeof(int *)));
            if(matriz == NULL){
                return 1;
            }
            /*Alocando os 9 números qeu possuem em cada linha*/
            for(int l = 0; l < 9; l++){
                matriz[l] = (int *) malloc(9 * sizeof(int));
                if(matriz == NULL){
                    return 1;
                }
            }

            /*Aqui acontece a leitrua do sudoku*/
        for(int l = 0; l < 9; l++){
            for(int c = 0; c < 9; c++){
                scanf("%d",&sudoku[l][c]);
            }
        }

        /*Aqui verificamos as linhas*/
        for(int l = 0; l < 9; l++){
            int linha[9];

            for(int c = 0; c < 9; c++){
                linha[c] = sudoku[l][c];
            }
            if(!verificar(linha)){
                blz = 0;
            }
        }
        /*Aqui verificamos as colunas*/
        for(int c = 0; c < 9; c++){
            int coluna[9];
            for(int l = 0; l < 9; l++){
                coluna[l] = sudoku[l][c];
            }
            if(!verificar(coluna)){
                blz = 0;
            }
        }
        /*Aqui verificamos os blocos 3x3*/
        for(int l = 0; l < 9; l = l + 3){
            for(int c = 0; c < 9; c = c + 3){
                int bloco[9], x = 0;
                for(int bloL = 0; bloL < 3; bloL++){
                    for(int bloC = 0; bloC  < 3; bloC++){
                        bloco[x++] = sudoku[l + bloL][c + bloC];
                    }
                }
                if(!verificar(bloco)){
                    blz = 0;
                }
            }
        }
        printf("Instancia %d\n", v + 1);
        if(blz == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
        printf("\n");

        /*Liberando as linhas*/
        for(int l = 0; l < 9; l++){
            free(matriz[l]);
        }

        /*Liberndo a memória da matriz criada pelo malloc*/
        free(matriz);
    }
    

    return 0;
}
