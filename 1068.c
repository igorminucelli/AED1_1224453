#include <stdio.h>
#include <string.h>

#define MAX 1005

typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

void empilhar(Pilha *p, char c) {
    p->topo++;
    p->dados[p->topo] = c;
}

void desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        p->topo--;
    }
}

int estaVazia(Pilha *p) {
    return p->topo == -1;
}

int verificarExpressao(char *str) {
    Pilha p;
    inicializar(&p);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') {
            empilhar(&p, '(');
        } else if (str[i] == ')') {
            if (estaVazia(&p)) {
                return 0;
            }
            desempilhar(&p);
        }
    }

    return estaVazia(&p);
}

int main() {
    char expressao[MAX];

    while (fgets(expressao, MAX, stdin) != NULL) {
        expressao[strcspn(expressao, "\r\n")] = '\0';

        if (verificarExpressao(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}
