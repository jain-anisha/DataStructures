#include<stdio.h>
#include<stdlib.h>

struct node
{   int val;
    struct node* next;
};

void swap(struct node * y, struct node *z){
    int temp = y -> val;
    y -> val = z -> val;
    z -> val = temp;
}

struct node * head = NULL; 
struct node * sorted = NULL;
// creating globals for the head and the sorted nodes
// head stores head of the linked list
// sorted points to the last term of the sorted part of the list

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


int sort(){
    /*compare 1st element to the next element..
    if the val of the first element is greater than the value of the next element, switch the values
    then, go to the next element in the unsorted list, compare
        if curr > next: switch vals 
        then, compare the last (already sorted) element in the list
    do the same until you sort all the elements

    NOTE; in the linked lists, we only switch the vals of the lnked list, the memory addresses stays the same. 

    IF the head does not exist, or the next -> next val of the head is NULL, then the linked list is doesnt exist, 
    or it os sorted
    */
   struct node * curr = head;
   struct node * nextnode;
   // intializing the first node to be pointing to the head node
    while (curr != NULL){
        //this will go through every node, incrementing by one everytime

        nextnode = curr -> next;
        //making a node that points to the next element of the list

        insert(curr );
        //essentially, this will make sure that rest of the partly sorted list will insert the next at the right place

        curr = nextnode;
        // making sure that in the next loop, the curr points to the next value
    }
}

void insert(struct node *new){
    /*
    two cases: 
    - 1: new is the head
    - 2: new is not the head

    when new is the head, sorted == NULL\
        - need to connect the head to the sorted node (new -> next = sorted)
        - update the new node to be the same as the sorted node  
    */
   if (sorted == NULL){
        new -> next = sorted;
        sorted = new;
   }
   //otherwise, need to put the new element at the right place of the sorted list
   /* if the new node's value is less than the current node's value, need to switch the values
   */
   else{
        struct node * curr = sorted;
        //to store the current node
        if()
   }
}

void main(){
    int num; 
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    linklist(num);

    sort();

    //print sorted linked list
}