/* Reversing a Linked List, given a linked list.

First, making a linked list, based on the code from the linked list
*/


//from the prev linked list code
struct Node
{   int val; // can only store integer data types
    struct Node* next;
    // creates a data type called Node that stores the data of the linkedlist and the point of the next node.
};

int revList(){
    
}

void Listprint(struct Node* head){
    struct Node* i = head;
    while (i != NULL) {
        printf("%d ", i->data);
        i = i->next;
    }
}

// linked list with four elements
int main()
{
    //making the nodes
    struct Node *a, *b, *c, *d;
 
    int input;

    a = malloc(sizeof(struct Node));
    b = malloc(sizeof(struct Node));
    c = malloc(sizeof(struct Node));
    d = malloc(sizeof(struct Node));


    printf("Insert value of first node: ");
    scanf("%d", &input);
    a -> val = input;
    printf("Insert value of second node: ");
    scanf("%d", &input);
    b -> val = input;
    printf("Insert value of third node: ");
    scanf("%d", &input);
    c -> val = input;
    printf("Insert value of fourth node: ");
    scanf("%d", &input);
    d -> val = input;

    struct Node* head = a;
    a -> next = b;
    b -> next = c;
    c -> next = d; 
    d -> next = NULL;

    //printing the list
    // end of the code from prev linkedlist

    //using i to traverse the list

    struct Node * i = head;
    printf("Original Linked List is: ")
    while (i!=NULL){
        printf("%d ", i->val);
        i = i -> next;
    }

    RevList()    
    return 0;

}