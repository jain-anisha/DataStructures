#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

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

struct node * linklist(int n){
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
    return head;
}

//in quick sort with linked lists, we will use the last value of the linked list as our pivot element:

struct node * findlast(struct node *head){
    //TRAVERSING THE LIST to find the last node
    if (head == NULL){
        return;             //linked list is not a list
    }
    //need to traverse the list, until the next element has NULL as the next address that it is pointing to 
    struct node *temp = head;       //temp var that will traverse list, starts at first element
    int i = 0;                      //index: counts num of loops
    while(temp-> next != NULL){
        temp = temp -> next;
        //now, temp must be: temp = temp -> next = NULL
    }
    assert(temp -> next == NULL);
    struct node *last = temp;
    //creating node to store the last element of the list
    return last;
}

void partition(struct node *first, struct node* last){
    // creating a partiton of greater and lesser values
    // the greater 
    //the pivot element, aka the last in the list
    // need a pointer for the greatest wall, and a pointer for the lesser wall, and the 
    // need a pointer for the current element as well.
    struct node *pivot, *greater, *less, *curr, *next;

    //last element is made to be the pivot
    pivot = last;
    //need a loop to go through entire list
    int i;
    for(i = 0; i < )
    // exit cond: when curr -> next -> next does not exist?
    
    
}

void qsort(struct node* start, struct node* stop){
    if ( start == NULL || start->val > stop->val){
        return;
    }

    struct node* wall = partition(*start, *stop);

    qsort(start, wall - 1);          // less list
    qsort(wall + 1, stop);           // greater list
}

void printL(){
{
    struct node * temp = head;
    // starting the temp value to the node of the head val
    while(temp->next != NULL)
    //will continue this loop until the last node
    {
        printf("%d\n", temp->val);
        temp = temp->next;
    }
    printf("%d\n", temp->val);
    // specifically printing out the last node
}

}

int main()
{
    int num; 
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    struct node * header = linklist(num);
    struct node * ender = findlast(header);
    qsort(header, ender);
}
