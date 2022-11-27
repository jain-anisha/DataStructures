#include<stdio.h>
#include<stdlib.h>

struct node{
    int val; 
    struct node *next;
    struct node *prev;
    // creating the node
};

//need a head

struct node *head = NULL;       //making the head node as a global

void linklist(int n){
    int val;
    struct node *temp;                  // points to the temp node 
    struct node *new;                   // new node placed here 
    struct node *before;                // prev node ptr

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == 0){
        return;
    }

    //head is the start of the linked list, that holds no value

    //now, writing the first node
    printf("Enter the values of %d nodes:\n", n);
    scanf("%d", &val);
    head -> next = NULL;                // the next pointer points to a null val
    head -> prev = NULL;                // prev points to nothing, as there is nothing before head
    head -> val = val;                  // the val in the node is the val inputed into function
    temp = head;                        // special condition for the first node, since we need to connect the head

    before = head;                      // before ptr intialized to head

    //now, need to link the other values
    // to do this, we will use a for loop
    // 1 <= i < n : INV
    for(int i = 1; i < n; i++){
        new = (struct node *)malloc(sizeof(struct node));
            // same the the previous print statement, no difference
            scanf("%d", &val);
            new -> next = NULL;     // the next ptr of the new node is NULL
            new -> val = val;       // the value of val in the new node is the inputted val
            new -> prev = before;

            temp -> next = new;     //connecting the new node to the list that already exists
            temp = temp -> next;
            before = before -> next;
    }
}

void Listprint(){
    struct node* i = head;
    struct node * last = head;
    printf("Printing the list forwards.");
    printf("\n");
    while (i != NULL) {
        printf("%d ", i->val);
        last = i;
        i = i->next;
    }
    printf("\n");
    printf("Printing the list backwards.");
    printf("\n");
    while (last != NULL){
        printf("%d ", last->val);
        last = last->prev;
    }
}

int main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    linklist(num);
    Listprint();
}



