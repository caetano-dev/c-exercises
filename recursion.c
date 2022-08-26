#include <stdio.h>

int recursion(int value){
    if (value == 10){
        return value;
    }
    printf("%d\n", value);
    return recursion(value+1);
}
int main () {
    printf("%d\n", recursion(1));
}
