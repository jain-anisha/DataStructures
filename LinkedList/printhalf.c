#include<stdio.h>
#include<stdlib.h>


// main code taken from create linked list code

//in this code, however, we will print the first half of the list, using the hare & the tortice method

struct node{
    int val; 
    struct node *next;
    // creating the node
};

//need a head

struct node *head = NULL;       //making the head node as a global

void linklist(int n){
    int val;
    struct node *temp;                  // points to the 
    struct node *new;

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == 0){
        return;
    }

    //head is the start of the linked list, that holds no value

    //now, writing the first node
    printf("Enter the values of %d nodes:\n", n);
    scanf("%d", &val);
    head -> next = NULL;                // the next pointer points to a null val
    head -> val = val;                  // the val in the node is the val inputed into function
    temp = head;                        // special condition for the first node, since we need to connect the head

    //now, need to link the other values
    // to do this, we will use a for loop
    // 1 <= i < n : INV
    for(int i = 1; i < n; i++){
        new = (struct node *)malloc(sizeof(struct node));
            // same the the previous print statement, no difference
            scanf("%d", &val);
            new -> next = NULL;     // the next ptr of the new node is NULL
            new -> val = val;       // the value of val in the new node is the inputted val

            temp -> next = new;     //
            new -> next == NULL;
            temp = temp -> next;
    }
}

void Listprint(){
    // modified for hare & tortice method

    //basically, to print one value of the linked list, we first must check if the next -> next pointer
    //... exists, AKA its not NULL

    struct node * tortoise = head;              // will jump forward one
    struct node * hare = head;                  // will jump forward two

    while(hare != NULL){
        //as long as the hare exists, we will print the tortoise value
        printf("%d ", tortoise->val);

        tortoise = tortoise -> next;
        // tortoise jumps forward one node
        hare = hare -> next -> next;
        // hare jumps forward two
    }

}

int main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    if (num <=1){
        printf("invalid input");
        return 0;
    }
    linklist(num);
    Listprint();
}
