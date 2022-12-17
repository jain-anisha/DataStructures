#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//in progress: need to see why seg faulting 

struct node {
    int val;
    struct node * left; //smaller branch
    struct node * right; // bigger branch
};

// we're looking at a single node at a time
//from there, flow to left or right arrow

typedef struct node * NodeAddress;

struct node * root = NULL;
//creating a global for the root

//intializing functions:
NodeAddress search (struct node * root, int input);
NodeAddress delete (int value);
NodeAddress successor (NodeAddress node);
struct node * newinput(int input, NodeAddress n);

NodeAddress new(int input){
    // mallocing space for a new node
    struct node * y = (struct node *)malloc(sizeof(struct node));
    // assigning values for the ptrs and val for the new node
    y -> val = input;
    y -> left = NULL;
    y -> right = NULL;
    assert(y -> right == NULL && y -> left == NULL);
    return y;
    //returning the new node 
}

struct node * newinput(int input, NodeAddress n){
    //if the root is NULL, then we place the new node 
    if (n == NULL){
        return new(input);
    }
    if (input > n -> val){
        (n -> right) = newinput(input, n -> right);
    }
    else{
        (n -> left) = newinput(input, n -> left);
    }
    return n;
    //calling itself recursively inorder to find the right place to input the new value
}

NodeAddress successor (NodeAddress node){
    /*
    to find: 
        - go to left children
        - continue going to the right child until right child does not exist
    */
    node = node -> left;
   
    while(node){
        node = node -> right;
    }
    return node;
}

NodeAddress search (struct node * root, int input){
    if (root == NULL) {
        return root;
    }
    else if(input > root -> val){
        return search(root -> right, input);
    }
    else if(input < root -> val){
        return search(root -> left, input);
    }
    else{
        return root;
    }
}

NodeAddress delete (int value){
    /*
    to delete a value in the BST, four cases:
        - value doesn't exist in BST
            - do nothing
        - value has no children
            - free the value's node
        - value has just one child
            - connect child to current node's parent
            - delete node
        - value has two children
            - find the successor of the value
            - copy the successor to the current node
            - delete the location of the OG successor
    */
    NodeAddress node = search(root, value);

    if(node == NULL){
        return NULL;
    }
    //can connect 2nd conditions to make it more simple

    if(node -> right == NULL){
        NodeAddress temp = node -> left;
        free(node);
    }
    else if(node -> left == NULL){
        NodeAddress temp = node -> right;
        free(node);
    }
    // both children exist:
    else{
        NodeAddress next = successor(node);
        node -> val = next -> val;              //copying value into 
        free(next);
    }
}

NodeAddress arrayToBST (int k){
    int data;           //stores inputted value of the BST node
    int array[k];       //intializing array where elements are inputted
    printf("Enter the values of the BST:");

    for (int i = 0; i < k; i++){        //inserting inputs into array
        scanf("%d", &array[i]);
    }

    root = new(array[0]);
    //prev error did not take in the last input, fixed it by inputting into an array

    for(int i = 1; i < k; i++){         // inserting values into the bst from the array
        root = newinput(array[i], root);
    }
    return root;
}


void printBST(struct node *root)
{
    // If the root node is NULL, return
    if (root != NULL){
        
        printf("-> %d\n", root->val);
        printBST(root->left);
        printBST(root->right);
        //free(root);
    }
}

void main(){
    
    int k;
    NodeAddress root;
    printf("Enter total number of nodes in the BST: \n");
    scanf("%d", &k);

    root = arrayToBST(k);
    printBST(root);

    int del;
    printf("Enter value to be deleted. ");
    scanf("%d", &del);
    printf("%d", del);
    delete(del);
    printBST(root);

    // making 24 the top of the bst
}
