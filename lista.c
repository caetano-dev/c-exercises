#include <stdio.h>
#include <stdlib.h>

int main()
{
    float *vetor = NULL;
    float temp;
    int numeroElementos = 0;
    vetor = malloc(numeroElementos * sizeof(*vetor));
    scanf("%d", &numeroElementos);

    for (int i = 0; i < numeroElementos; i++)
    {
        scanf("%f", &vetor[i]);
    }
    for (int i = 0; i <= numeroElementos - 1; i++)
    {
        for (int c = 0; c <= numeroElementos - 2 - i; c++)
        {
            if (vetor[c] < vetor[c + 1])
            {
                temp = vetor[c];
                vetor[c] = vetor[c + 1];
                vetor[c + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numeroElementos; i++)
    {
        if (vetor[i] == (int)(vetor[i]))
        {
            printf("%.1d\t", (int)vetor[i]);
        }
        else
        {
            printf("%.1f\t", vetor[i]);
        }
    }

    free(vetor);
    return 0;
}