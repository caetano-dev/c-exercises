#include <stdio.h>

typedef struct node{
    int value;
    struct node *next;
} node;

void printValue(node *head){
    node *temp = head;
    while(temp!=NULL){
        printf("%d", temp->value);
        temp = temp->next;
    };
    printf("\n");
}

int main(){
    node *head = NULL;
    node item1;
    node item2;
    node item3;

    head = &item1;

    item1.value = 10;
    item2.value = 20;
    item3.value = 30;

    item1.next = &item2;
    item2.next = &item3;
    item3.next = NULL;

    printValue(head);
}
