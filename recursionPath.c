#include <stdio.h>

int path(int m, int n){
    if (m == 1 || n==1){
        return 1;
    }
    else{
        printf("%d and %d\n", m, n);
        return path(m, n-1)+path(m-1, n);
    }
}
int main(){
    printf("%d", path(20,9));
    return 0;

}

