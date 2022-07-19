#include <stdio.h>

int mmc(int numeroMenor, int numeroMaior);
int ordenarNumero(int primeiroNumero, int segundoNumero);

int main()
{
    int primeiroNumero, segundoNumero;
    printf("Digite os numeros: ");
    scanf("%d", &primeiroNumero);
    scanf("%d", &segundoNumero);
    ordenarNumero(primeiroNumero, segundoNumero);
}

int ordenarNumero(int primeiroNumero, int segundoNumero)
{
    if (primeiroNumero > segundoNumero)
    {
        printf("%d", mmc(primeiroNumero, segundoNumero));
    }
    else
    {
        printf("%d", mmc(segundoNumero, primeiroNumero));
    }
}

int mmc(int numeroMenor, int numeroMaior)
{
    int i;
    for (i = numeroMaior; i >= 1; i--)
    {
        if (numeroMaior % i == 0 && numeroMenor % i == 0)
        {
            break;
        }
    }
    return i;
}