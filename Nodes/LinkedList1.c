#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val; // can only store integer data types
    struct Node* next;
    // creates a data type called Node that stores the data of the linkedlist and the point of the next node.
}


// linked list with four elements
int main{
    //making the nodes
    struct Node *head, *a, *b, *c, *d;

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
    b -> val =input;
    printf("Insert value of third node:");
    scanf("%d", &input);
    c -> val = input;
    printf("Insert value of fourth node:");
    scanf("%d", &input);
    d -> val = input;      
    
    /*int n; //number of elements in the list
    int i; //index of element (counter)

    for(i=0, i<n, i++){
        if (head == NULL)
        {
            return NULL
            //With no head value, the linked list does not exist
        }
        else
        {
            pointer = malloc(sizeof (Node));
            prev -> pointer //previous node points to next node
            prev -> pointer -> pointer //previous pointer points to the next next pointer

        }
        prev = p
        
    }*/
}
//This was a very bad first attempt at writing a linked list. Have an understanding of it. but is still confused on writing it