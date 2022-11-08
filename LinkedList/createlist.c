#include<stdio.h>
#include<stdlib.h>

struct node{
    int val; 
    struct node *next;
    // creating the node
};

//need a head

struct node *head = NULL;       //making the head node as a global

void linklist(int n){
    int val;
    struct node *temp;
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
    temp = head;

    //now, need to link the other values
    // to do this, we will use a for loop
    // 2 <= i < n : INV
    for(int i = 1; i < n; i++){
        new = (struct node *)malloc(sizeof(struct node));
            
            scanf("%d", &val);
            new -> next = NULL;     // the next ptr of the new node is NULL
            new -> val = val;       // the value of val in the new node is the inputted val

            temp -> next = new;     //
            temp = temp -> next;
    }
}

int main()
{
    int num; 

    printf("Enter number of nodes: ");
    scanf("%d", &num);
    linklist(num);

}



