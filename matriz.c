#include <stdio.h>

int main()
{
    float data[20][20];
    for (int g = 0; g < 3; g++)
    {
       for(int p = 0; p < 3; p++){
        scanf("%f", &data[g][p]);
       }
    }
    printf("%.2f", data[0][0] * data[1][1] * data[2][2] + data[0][1] * data[1][2] * data[2][0] + data[0][2] * data[1][0] * data[2][1] - data[2][0] * data[1][1] * data[0][2] - data[2][1] * data[1][2] * data[0][0] - data[2][2] * data[1][0] * data[0][1]);

    return 0;
}