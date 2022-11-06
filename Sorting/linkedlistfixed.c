#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val; // can only store integer data types
    struct Node* next;
    // creates a data type called Node that stores the data of the linkedlist and the point of the next node.
};


// linked list with four elements
int main()
{
    //making the nodes
    struct Node *a, *b, *c, *d;
 
    int input;

    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));


    printf("Insert value of first node:");
    scanf("%d", &input);
    a -> val = input;
    printf("Insert value of second node:");
    scanf("%d", &input);
    b -> val = input;
    printf("Insert value of third node:");
    scanf("%d", &input);
    c -> val = input;
    printf("Insert value of fourth node:");
    scanf("%d", &input);
    d -> val = input;

    struct Node* head = a;                  //linking the list together
    a -> next = b;
    b -> next = c;
    c -> next = d; 
    d -> next = NULL;

    //printing the list

    //using i to traverse the list

    struct Node * i = head;
    while (i!=NULL){
        printf("%d points to ", i->val);
        i = i -> next;
    }
    printf("NULL");
    
    return 0;

}


// Is it possible to write a linkedlist with a variable number of elements?

