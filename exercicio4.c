/*calcular o fatorial de um numero inteiro positivo */
#include <stdio.h>

int main() {
    int number, i, factorial;
    printf("Digite um numero ");
    scanf("%d", &number);
    factorial = 1;
    for (i = 1; i <= number; i++) {
        factorial = factorial * i;
    }
    printf("%d! = %d", number, factorial);
}
