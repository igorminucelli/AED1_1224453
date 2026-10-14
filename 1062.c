
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
