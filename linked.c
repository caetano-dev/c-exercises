#include <stdio.h>

struct node{ 
    int value;
    struct node* next;
};

void printlist(struct node *head){
    struct node *temporary = head;
    while(temporary != NULL){
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");

}

int main()
{
    struct node n1, n2, n3;
    struct node *head;
    n1.value = 1;
    n2.value = 2;
    n3.value = 3;
    //link them
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;
    //add a new one
    struct node n4;
    n4.value = 4;
    n1.next = &n4; 
    n4.next = NULL;

    
    printlist(head);
    return 0;
}
