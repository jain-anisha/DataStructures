#include<stdio.h>
#include<stdlib.h>

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
            temp = temp -> next;
    }
    // the temp now stores the last made node
    // to connect last node to head we do:

    temp -> next = head;
}

void Listprint(struct node * z, int n){
    int i = 0;
    while (i != n) {
        printf("%d ", z->val);
        z = z -> next;
        i++;
    }
}

int circularChecker(int n){
    /*
    traverse the list with two values: tortoise & hare
        - tortoise goes one ahead
        - hare goes two head
        - if hare < tortoise, it is a circular list
    */
    struct node *h = head;
    struct node *two = head -> next;

    while(two != NULL && two != h){
        two = two -> next;
        if (h == two){
            return 1;
        }
    }
    return 0;
}

void main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    if (num <=1){
        printf("invalid input");
        return 0;
    }
    linklist(num);
    Listprint(head, num);

    int out = circularChecker(num);
    if (out == 1) {
        printf("It is a circular linked list.");
    }
    else {
        printf("It is not a circular linked list.");
    }
    // how do we print a list?? no clue if code is correct as of now
}