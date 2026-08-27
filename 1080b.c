/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Igor Aparecido Minucelli Pinto>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1080>>
Data        : 24/08/2026
Objetivo    : Ler um vetor de 100 inteiros e mostrar o maior valor entre eles e a posição.
Dificuldade : <<<Não houve dificuldade>>>
Uso de IA   : <<<Se usou, descreva brevemente o uso de IA na solução>>>
-------------------------------------------------------------------------- */
#include<stdio.h>
#include<stdlib.h>

int main(){
    int X[100], maior, posi;
    int *vetor;
  
    /*Aqui estou lendo a primeira posição do vetor e assumindo que ela é a maior e dando a posição*/
    scanf("%d", &X[0]);
    maior = X[0];
    posi = 0;
  
    /*Criando a alocação dinâmica*/
    vetor = ((int *) malloc(100 * sizeof(int)));
    /*Se a alocação deu errado returna 1*/
    if(vetor == NULL){
        return 1;
    }

    /*Preenchendo o vetor; OBS: O laço for inicia em 1, pois a primeira posição já foi lida*/
    for(int i = 1; i < 100; i++){
        scanf("%d", &X[i]);
        if(X[i] > maior){
            maior = X[i];
            /*i + 1, pois o vetor começa em 0 e não em 1*/
            posi = i + 1;
        }
    }
    printf("%d\n", maior);
    printf("%d\n", posi);

    /*Liberando a memória usada pelo malloc*/
    free(vetor);
    
    return 0;
}
