#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int mystack[MAX_N];
int top = EMPTY;

int push(int value){
    if (top>= MAX_N-1) return false;
    top++;
    mystack[top] = value;
    return true;
}

int pop(){
    if (top == EMPTY) return STACK_EMPTY;
    int result = mystack[top];
    top--;
    return result;
}

int main(){
    push(56);
    push(23);
    push(42);

    int t;
    while((t=pop()) != STACK_EMPTY){
       printf("t = %d\n", t); 
    }

    return 0;
}
