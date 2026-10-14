/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Igor Aparecido Minucelli Pinto>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 14/10/2026
Objetivo    : Dado um vagão com determinada quantidade de carga(sendo valores) devemos organizar para saber se é possivel passar pelo trilho
Dificuldade : <<<Como usar o vagão atual, em que empilharemos ou desempilharemos>>>
Uso de IA   : <<<Usei para entender como por em pratica o uso das pilhas e entender melhor o enunciado do problema>>>
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* proximo;
} no;

void empilha(int novovalor, no* cabeça) {
    no* novo = malloc(sizeof(no));
    novo->valor = novovalor;
    novo->proximo = cabeça->proximo;
    cabeça->proximo = novo;
}

int desempilha(no* cabeça) {
    if (cabeça->proximo == NULL) {
        return -1;
    }
    no* aux = cabeça->proximo;
    cabeça->proximo = aux->proximo;
    int valorremovido = aux->valor;
    free(aux);
    return valorremovido;
}

int main() {
    int n;

    while (scanf("%d", &n) && n != 0) {
        int x[n];

        while (1) {
            scanf("%d", &x[0]);
            if (x[0] == 0) {
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &x[i]);
            }

            no* cabeca = malloc(sizeof(no));
            cabeca->proximo = NULL;

            int vagao_atual = 1;
            int possivel = 1;

            for (int i = 0; i < n; i++) {
                while (cabeca->proximo == NULL || cabeca->proximo->valor != x[i]) {
                    if (vagao_atual > n) {
                        possivel = 0;
                        break;
                    }
                    empilha(vagao_atual, cabeca);
                    vagao_atual++;
                }

                if (!possivel) {
                    break;
                }

                desempilha(cabeca);
            }

            if (possivel) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }

            while (cabeca->proximo != NULL) {
                desempilha(cabeca);
            }
            free(cabeca);
        }
        printf("\n");
    }

    return 0;
}
