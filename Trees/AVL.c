#include<stdio.h>
#include<stdlib.h>

//IN PROGRESS

// basically a way to balance out a binary search tree

//to make AVL, we first must make a binary search tree.
//AVL is in place WHILE making the binary search tree

struct node
{
    int val;
    struct node *left;
    struct node *right;
    int height;
};

// we're looking at a single node at a time
//from there, flow to left or right arrow

typedef struct node * NodeAddress;

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
    //returns height of a node
}

struct node * new(int input){
    // mallocing space for a new node
    struct node * y = (struct node *)malloc(sizeof(struct node));
    // assigning values for the ptrs and val for the new node
    y -> val = input;
    y -> left = NULL;
    y -> right = NULL;
    y -> height = 1;
    // as we are inserting the node at a leaf
    return y;
    //returning the new node 
}

struct node * newinput(struct node * root, int input){
    //if the root is NULL, then we place the new node 
    if (root == NULL){
        return new(input);
        // found the current leaf, inserting the node here
    }
    //three cases: input greater than root, input less than root, or the input is the root
    if (input < root -> val){
        root -> left = newinput(root -> left, input);
    }
    else if (input > root -> val){
        root -> right = newinput(root -> right, input);
    }
    return root;
    //calling itself recursively inorder to find the right place to input the new value
}

void main(){
    struct node * root = NULL;
    //intializing the first node as NULL
    
    // making 24 the top of the bst
}



