#include<stdio.h>
#include<stdlib.h>

//reversing the list, printing out every other element, when the number of nodes is even

struct node{
    int val; 
    struct node *next;
    // creating the node
};

//need a head
struct node *head = NULL;       //making the head node as a global

void linklist(int n){
    //taken from create list code
    int val;
    struct node *temp;                  // points to the 
    struct node *new;

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 1 || head == NULL){
        printf("invalid input");
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
}

struct node * doThis(struct node * head){

    struct node* prevr, *currr ;

    struct node * tempr = (struct node *)malloc(sizeof(struct node));

    tempr = head;
    // creating new head node


    //first need to change the head

    prevr = tempr;
    //pointing the prev node to the head node

    currr = tempr -> next;
    //curr node points to the node after head

    tempr = tempr -> next;
    //temp node points to the next node

    prevr -> next = NULL;
    //now, the prev node has no next node, since the direction of the head {AKA the tempr} has been switched to 
    //...the other direction

    while(tempr != NULL){               //as long as there is a node 
        tempr = tempr -> next -> next;          // head now points to the next val
        currr -> next = prevr;          // the prev now points to the same thing curr-> next is pointing to  

        prevr = currr;                 
        currr = tempr;
    }
    return prevr; 
}

void Listprint(struct node * start){
    struct node* i = start;
    printf("The linked list is: ");
    while (i -> next != NULL) {
        printf("%d ", i->val);
        i = i->next;
    }
}

int main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    if(num % 2 == 0){
        printf("insert an odd number of nodes");
        return 0;
    }
    linklist(num);
    struct node * out = doThis(head);
    Listprint(out);
    // how do we print a list?? no clue if code is correct as of now
}