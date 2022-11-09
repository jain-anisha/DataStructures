#include<stdio.h>
#include<stdlib.h>

struct node
{   int val;
    struct node* next;
};

//we will need a head, end, and nodes in between
struct node* head = NULL;
struct node* end = NULL;

void swap(struct node * y, struct node *z){
    int temp = y -> val;
    y -> val = z -> val;
    z -> val = temp;
}

void linklist(int n){
    //TAKEN FROM LINKED LIST
    int val;
    struct node *temp;
    struct node *new;

    head = (struct node *)malloc(sizeof(struct node));      //making the head node

    if(n <= 0 || head == 0){
        return;}

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

//in quick sort with linked lists, we will use the last value of the linked list as our pivot element:

struct node* last(struct node *head){
    //TRAVERSING THE LIST to find the last node
    if (head == NULL){
        return;             //linked list is not a list
    }


}

void partition(struct node *first, struct node* last, size){
    //the pivot element, aka the last in the list
    // need a pointer for the greatest wall, and a pointer for the lesser wall, and the 
    // need a pointer for the current element as well.
    struct node *pivot, *greater, *less, *curr, *next;

    //last element is made to be the pivot
    pivot = last;
    //need a loop to go through entire list
    int i;
    // exit cond: when curr -> next -> next does not exist?
    
    
}

void qsort(struct node* start, struct node* stop, size){
    if (last == NULL || start == NULL || start->val > stop->val){
        return;
    }

    struct node* wall = partition(struct node * first, struct node * last);

    qsort(start, wall - 1, size);          // less list
    qsort(wall + 1, stop, size);           // greater list
}

void printL(){
    // printing the linked list
    while()
}

int main()
{
    int num; 
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    linklist(num);
}
