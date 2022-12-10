#include<stdio.h>
#include<stdlib.h>

//creating a stack with a doubly linked list

//parts taken from createlist.c code
struct node{
    int val; 
    struct node *next;
    struct node *prev;
    // creating the node
};

struct node *head = NULL;       //making the head node as a global

struct node * linklist(int n){
    int val;
    struct node *temp;                  // points to the temp node 
    struct node *new;                   // new node placed here 
    struct node *before;                // prev node ptr

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == NULL){ return head; }

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
    return temp;
    printf("STACK CREATED SUCCESSFULLY");
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
}

int enterEle(struct node * last){
    /*
    the start of the stack stays the same
    - user inputs the number of elements to be entered.
    - user enters values of the elements
    - do the same thing as the loop in creating a list does
    - return the list
    */
    int input, value;                           //
    struct node * newNode;
    struct node * temp = last;
    struct node * before = last;
    int i = 0;

    printf("Enter the number of elements to be entered: ");
    scanf("%d", &input);

    if(input < 1){
        printf("Please enter an input greater than zero.\n");
        return 4;
    }

    printf("Enter %d values of the elements: \n", input);
    while(i < input){
        newNode = (struct node *)malloc(sizeof(struct node));
            // same the the previous print statement, no difference
            scanf("%d", &value);
            newNode -> next = NULL;     // the next ptr of the new node is NULL
            newNode -> val = value;       // the value of val in the new node is the inputted val
            newNode -> prev = before;

            temp -> next = newNode;     //connecting the new node to the list that already exists
            temp = temp -> next;
            before = before -> next;
            i++;
    }
    return 1;
}

int deleteEle(struct node * head, int n){
    /*
    free the last x nodes, in a loop
    */
    int input;
    struct node * temp = head;
    struct node * delete = head;
    int i = 0;

    printf("Enter the number of elements to be deleted: ");
    scanf("%d", &input);

    if(input > n || input < 1){ 
        printf("Enter an integer less than %d and greater than zero.\n", input);
        deleteEle(head, n);
    }

    if(input == n){
        while(i + 1 < input){
            temp = temp -> next;
            free(delete);
            delete = temp;
            i++;
        } 
        free(delete);
        return 0;
    }

    else{
        while(i < input){
            temp = temp -> next;
            temp -> prev = NULL;
            free(delete);
            delete = temp;
            i++;
        }
        return 1; 
    }
}

int stackFunc(struct node * last, int n){
    int userInput;
    int out;

    printf("\nWould you like to enter or delete elements from the stack? \n");
    printf(" Enter 1 to enter more elements. \n Enter 2 to delete elements. \n Enter anything else to exit.\n");
    scanf("%d", &userInput);

    if(userInput == 1){
        return enterEle(last);
        
    }
    else if (userInput == 2){
        return deleteEle(head, n);
    }
    else { return 10; }
}

int main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    struct node * last = linklist(num);
    Listprint();

    int out = stackFunc(last, num);

    if(out == 1){
        Listprint();
    }
    else if(out == 0){
        printf("Queue is empty");
    }
    else{
        printf("Queue has not changed.");
    }
}