#include<stdio.h>
#include<stdlib.h>

//most of the code is from the code for reversing a list
// modifying so it reverses only half

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

struct node * revList(int n){
    /*
    hare & tortoise:

    to reverse only half of the list, we need to have two different pointers to the current value:
    - hare: that will jump forward two nodes
    - tortoise: that will jump forward one node 

    as long as hare != NULL, we will reverse the values of the list.
        first, we would traverse the list, and see where the middle of the list is
            - this would sorted in the tortise ptr
        - then, would reverse the elements in the list now, as given in the rev function, until temp -> next == tortoise

    ** problem: how do we connect the two lists then?
        SOLUTION: point the last element of the switched list (AKA THE ORIGINAL HEAD) to the first node
        where the node did not switch directions:
        Do this by:
            - say we have 9 elements:
            - the first 4 elements will be reversed
                - AKA the middle element WILL NOT be reversed.

        - in other words, the original head would point to the same node that tortoise points to 
    */ 
    struct node * tortoise = head;              // will jump forward one
    struct node * hare = head;                  // will jump forward two

    //have two cases: odd and even number of elements
    // have this, because without it, the code was seg faulting while checking the exit

    if (n % 2 == 0){
        while(hare != NULL){

            tortoise = tortoise -> next;
        // tortoise jumps forward one node
            hare = hare -> next -> next;
        // hare jumps forward two
    }  
    }

    if (n % 2 == 1){
        while(hare -> next!= NULL){
        // in the case of an odd number of elements, we will not print out the middle element
            tortoise = tortoise -> next;
        // tortoise jumps forward one node
            hare = hare -> next -> next;
        // hare jumps forward two
    }
    }
   


    //comments are now from the prev reverse code
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

    while(tempr != tortoise){               //as long as the next element is not the middle element
        tempr = tempr -> next;          // head now points to the next val
        currr -> next = prevr;          // the prev now points to the same thing curr-> next is pointing to  

        prevr = currr;                 
        currr = tempr;
    }

    // now, need to connect everything together:
    head -> next = tortoise;
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
    
    f = revList(num);
    Listprint(f);    
    return;
}