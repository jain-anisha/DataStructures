#include<stdio.h>
#include<stdlib.h>

/* Reversing a Linked List, given a linked list.

First, making a linked list, based on the code from the linked list
*/

//from the prev linked list code
struct node{
    int val; 
    struct node *next;          // creating the node
};

struct node *head = NULL;       //making the head node as a global

void linklist(int n);
struct node * revList();

void linklist(int n){
    //taken from create linked list code
    int value;
    struct node *temp;
    // the code from the last push was seg faulting, and I did not understand why it was seg faulthin

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 1 || head == 0){
        printf("invalid inputs");
        return;
    }

    //head is the start of the linked list, that holds no value

    //now, writing the first node
    printf("Enter the values of %d nodes:\n", n);
    scanf("%d", &value);

    head -> val = value;
    head -> next = NULL;

    temp = head;    

    //now, need to link the other values
    // to do this, we will use a for loop
    // 1 <= i < n : INV
    for(int i = 2; i <= n; i++){
        
        struct node * newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &value);
        newnode->val = value;
        newnode->next = NULL;
        temp -> next = newnode;
        temp = temp->next;
    }
    return;
}

void Listprint(struct node * z){
    struct node* i = z;
    while (i != NULL) {
        printf("%d ", i->val);
        i = i->next;
    }
}

struct node * revList(){
    //essentially, when we are given the head node, we switch the head node
    // we make the head node point to NULL, while having another pointer point to another

    /* We need 3 pointers: one to point at the current node, one to point at prev node, and one to point at next node
    while the current node is NOT pointing to a NULL val (AKA is not the last val in the list), store the next ptr
    as the current pointing to the next val, 
    then, reverse the ptr of the current,
    then, move the ptrs one step ahead

    INV: prev < current < next
    exit condition: when current == NULL (aka, we have reached the end of the linked list)

    after switching all the values, we need to deal with the previous head
    we put the head ptr to the last prev val, and we have finished

    */
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
        tempr = tempr -> next;          // head now points to the next val
        currr -> next = prevr;          // the prev now points to the same thing curr-> next is pointing to  

        prevr = currr;                 
        currr = tempr;
    }
    return prevr;   // this is where the new head of the list is
}

void main()
{
    int num; 
    struct node * f;

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    if(num <= 1){
        printf("invalid input");
        return;
    }
    linklist(num);
    
    f = revList();
    Listprint(f);    
    return;
}