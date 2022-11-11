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

void revList(){
    //essentially, when we are given the head node, we switch the head node
    // we make the head node point to NULL, while having another pointer point to another
    //if(!head){
      //  return;}        //if head does not exist, there's no linked list
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

    struct node * temp = (struct node *)malloc(sizeof(struct node));

    temp = head;
    struct node* curr = temp;


    //first need to change the head

    prev = temp;

    curr = temp -> next;

    temp = temp -> next;

    prev -> next = NULL;

    while(head != NULL){
        temp = temp -> next;
        curr -> next = prev;

        prev = curr;
        curr = temp;
    }
    head = prev;
    return;
}

void linklist(int n){
    //taken from create linked list code
    int value;
    //struct node *temp;                  // points to the 
    struct node *new;
    //struct node *head = NULL;       //making the head node as a global


    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == 0){
        return;
    }

    //head is the start of the linked list, that holds no value

    //now, writing the first node
    printf("Enter the values of %d nodes:\n", n);

    //now, need to link the other values
    // to do this, we will use a for loop
    // 1 <= i < n : INV
    for(int i = 0; i < n; i++){
        struct node * temp = head;
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
            scanf("%d", &value);
        newnode->val = value;
        newnode->next = NULL;
        if(head==NULL){
            head = newnode;
        }
        else{
            while(temp -> next != NULL){
                temp = temp->next;
            }  
        } //
            temp -> next = newnode;
    }
    return;
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
    linklist(num);
    Listprint(head); 
    // how do we print a list?? no clue if code is correct as of now
    revList();
    Listprint(head);    
    return 0;
}