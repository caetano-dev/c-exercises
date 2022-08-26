#include <stdio.h>

int sumOfNumbers(int value){
    if (value <= 1){
        return value;
    }
    return value + sumOfNumbers(value-1);
}

int main () {
    printf("%d\n", sumOfNumbers(10));
}
