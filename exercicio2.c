/*2) Escreva um programa em C que verifique se um determinado inteiro positivo que é lido via teclado, é ou não primo.*/
#include <stdio.h>

int main() {
    int number;
    int i;
    int isPrime = 1;
    printf("Digite um numero ");
    scanf("%d", &number);
    for (i = 2; i<number;i++){
        if (number % i ==0){
            isPrime = 0;
        }
    }
    if (isPrime){
        printf("%d é primo", number);
    }
    else{
        printf("%d não é primo", number);
    }
}
