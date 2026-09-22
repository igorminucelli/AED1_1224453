/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : <<<Igor Aparecido Minucelli Pinto>>>
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/<<1068>>
Data        : 21/09/2026
Objetivo    : Dada uma expressão que possui parênteses, devemos dizer se a quantidade de parênteses está correta.
Dificuldade : <<<Usar a pilha para resolver >>>
Uso de IA   : <<<Usei para entender como por em pratica o uso das pilhas e entender melhor o enunciado do problema>>>
-------------------------------------------------------------------------- */
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
