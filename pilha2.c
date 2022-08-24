#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_N 10
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node{
    int value;
    struct node *next;
} node;

node* head = NULL;

int mystack[MAX_N];
int top = EMPTY;

int push(int value){
    node *newnode = malloc(sizeof(node));
    if(newnode == NULL) return false;
    newnode-> value= value;
    newnode-> next= head;
    head = newnode;
    return true;
}

int pop(){
    if (head == NULL) return STACK_EMPTY;
    int result = head->value;
    node *tmp = head;
    head = head->next;
    free(tmp);
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
