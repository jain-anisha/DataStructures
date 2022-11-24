#include<stdio.h>
#include<stdlib.h>

struct node
{   int val;                //create node structure
    struct node* next;
};

struct node * head = NULL;      //intializing the global variable 

void swap(struct node * y, struct node *z){
    int temp = y -> val;
    y -> val = z -> val;
    z -> val = temp;
}

void linklist(int n){
    //taken from the create linked list code
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
}

void Listprint(struct node * i){
    while (i != NULL) {
        printf("%d ", i->val);
        i = i->next;
    }
}


// Linked Lists do not allow random access, so we must traverse the list to get each element
// ... each time

void selsort(){
// selection sort works by chosing the smallest value, placing it at the front of the list, and then decrementing the
/*... size of the list by one

so, in a linked list, we will be swapping the ptrs of the list
in order to do this, we will need to have a pointer to save the end of the sorted array
    - intialized as the head node

another pointer that traverses the entire list 
    - intialized as head -> next

a variable that saves the current smallest value
    - intialized as value of head

we have a base case where 
*/
struct node * out = head;
struct node * curr = head -> next; 

int j = 0;

while(out != NULL){
    struct node * curr = out -> next;
    while(curr != NULL){
        if (out -> val > curr -> val){
            swap(out, curr); 
        }
        curr = curr -> next;
    }
    out = out -> next;
}
}

void main(){
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    if (num <=1){
        printf("invalid input");
        return;
    }
    linklist(num);
    selsort();
    Listprint(head);
}
