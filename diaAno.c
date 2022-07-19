#include <stdio.h>

int bissexto(int ano);

int main()
{
    int dia, mes, ano, numeroDeDias;
    printf("Digite o dia\n");
    scanf("%d", &dia);
    printf("Digite o mes\n");
    scanf("%d", &mes);
    printf("Digite o ano\n");
    scanf("%d", &ano);

    switch (mes)
    {
    case 1:
        numeroDeDias = 0;
        break;
    case 2:
        numeroDeDias = 31;
        break;
    case 3:
        numeroDeDias = 59;
        break;
    case 4:
        numeroDeDias = 90;
        break;
    case 5:
        numeroDeDias = 120;
        break;
    case 6:
        numeroDeDias = 151;
        break;
    case 7:
        numeroDeDias = 181;
        break;
    case 8:
        numeroDeDias = 212;
        break;
    case 9:
        numeroDeDias = 243;
        break;
    case 10:
        numeroDeDias = 273;
        break;
    case 11:
        numeroDeDias = 304;
        break;
    case 12:
        numeroDeDias = 334;
        break;
    default:
        numeroDeDias = 0;
    }
    if (bissexto(ano) == 0)
    {
        if (numeroDeDias + dia >= 58)
        {
            printf("%d", numeroDeDias + dia + 1);
        }
        else
        {
            printf("%d", numeroDeDias + dia);
        }
    }
    else
    {
        printf("%d", numeroDeDias + dia);
    }
    return 0;
}

int bissexto(int ano)
{
    if (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0))
    {
        return 0;
    }
}
