#include <stdio.h>
#include <stdlib.h>
int buscabinaria(int n, int vetor[], int inicio, int fim){
    if (inicio > fim){
	return -1;   
   }
    int meio = (inicio + fim)/2;
    if (vetor[meio] == n){
    return meio;
    }
    if (n > vetor[meio]){
      	return buscabinaria(n, vetor,meio+1, fim);
     }
     else{
      return buscabinaria(n, vetor, inicio, meio -1);
     }
}
int main()
{
    int num, i, vetor[101];
    printf("Digite um numero: ");
    scanf(" %d", &num);
    if (num < 0 || num > 100){
        printf("Valor invalido!\n");
        return 0;
    }
   for(i = 0; i <=100; i++){
	vetor[i] = i;	
	}
    printf (" O valor eh: %d \n ", buscabinaria(num, vetor, 0, 100));
	    return 0;
	}

