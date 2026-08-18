#include<stdio.h>
int main(){
  
    int N, menor, posi;
    
    scanf("%d",&N);
    int X[N];
    scanf("%d",&X[0]);
    menor = X[0];
    posi = 0;
    for(int i = 1; i < N; i++){
        scanf("%d", &X[i]);
        if(menor > X[i]){
            menor = X[i];
            posi = i;
        } 
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posi);
    
    
    return 0;
}
