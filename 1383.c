#include<stdio.h>

int sudoku[9][9];

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

    if(scanf("%d", &n) != 1){
        return 0;
    }
    for(int v = 0; v < n; v++){
        int blz = 1;
        for(int l = 0; l < 9; l++){
            for(int c = 0; c < 9; c++){
                scanf("%d",&sudoku[l][c]);
            }
        }
        for(int l = 0; l < 9; l++){
            int linha[9];
            for(int c = 0; c < 9; c++){
                linha[c] = sudoku[l][c];
            }
            if(!verificar(linha)){
                blz = 0;
            }
        }
        for(int c = 0; c < 9; c++){
            int coluna[9];
            for(int l = 0; l < 9; l++){
                coluna[l] = sudoku[l][c];
            }
            if(!verificar(coluna)){
                blz = 0;
            }
        }
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
    }
    return 0;
}
