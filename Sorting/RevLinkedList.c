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


int revList(struct node* header){
    //essentially, when we are given the head node, we switch the head node
    // we make the head node point to NULL, while having another pointer point to another
    if(!header){
        return NULL;}        //if head does not exist, there's no linked list
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
    struct node* prev = NULL ;
    struct node* next = NULL;
    struct node *curr = header;

    while(curr != NULL){
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr = next;
    }
    header = prev;
    return header;
}

struct node * linklist(int n){
    //taken from create linked list code
    int val;
    struct node *temp;                  // points to the 
    struct node *new;
    struct node *head = NULL;       //making the head node as a global


    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == 0){
        return head;
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
    return head;
}

void Listprint(struct node* head){
    struct node* i = head;
    while (i != NULL) {
        printf("%d ", i->val);
        i = i->next;
    }
}

// linked list with four elements

int main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    struct node *head = linklist(num);
    // how do we print a list?? no clue if code is correct as of now
    struct node * s = revList(head);
    Listprint(s);    
    return 0;
}