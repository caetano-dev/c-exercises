#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroElementos, *ptr = 0;
    ptr = (int *)malloc(numeroElementos * sizeof(float));
    scanf("%d", &numeroElementos);
    float elementos[numeroElementos], temp;

    for (int i = 0; i < numeroElementos; i++)
    {
        scanf("%f", &elementos[i]);
    }
    for (int i = 0; i <= numeroElementos - 1; i++)
    {
        for (int c = 0; c <= numeroElementos - 2 - i; c++)
        {
            if (elementos[c] < elementos[c + 1])
            {
                temp = elementos[c];
                elementos[c] = elementos[c + 1];
                elementos[c + 1] = temp;
            }
        }
    }
    for (int i = 0; i < numeroElementos; i++)
    {
        printf("%.1f\n", elementos[i]);
    }

    free(ptr);
    return 0;
}