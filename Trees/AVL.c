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
    else{
        return root;
    }
    //calling itself recursively inorder to find the right place to input the new value
    int bal = balanceVal(root);
    /* now, must see if the tree is imbalanced, and balance it
    five cases for bal's value:
        - balanced:
            - bal = 0 or 1 or -1
            - nothing needs to be done
        - left left imbalanced
            - bal > 1
            - input < node's left child's val
                - right rotate
        - left right imbalanced
            - bal > 1
            - input > node's left child's val
                - node -> left: right rotate
                - right rotate
        - right right imbalanced
            - bal < -1 
            - input > node's right child's val
                - left rotate
        - right left imbalanced
            - bal < -1
            - input < node's right child's val
                - node -> right: left rotate
                - left rotate
    */
    if (bal > 1){
        if(input < root -> left -> val){                //left left 
            return rightRotate(root);
        }
        else if(input > root -> left -> val){           //left right
            root -> left = leftRotate(root -> left);
            return rightRotate(root);
        }
    }
    else if (bal < -1){
        if(input > root -> right -> val){               //right right
            return leftRotate(root);
        }
        else if(input < root -> right -> val){          //right left
            root -> right = rightRotate(root -> right);
            return leftRotate(root);
        }
    }
   return root;
}

struct node * leftRotate(struct node * node1){
    /* new top is node1 -> right
    
    */
}

struct node *rightRotate(struct node * node2){

}

int balanceVal(struct node * n){
    /*
    in order to balance a tree, need to know the weights of both sides of the tree

    when the node is NULL, the tree must also be empty, so both sides of the tree is the same, which makes
    ... the balance zero

    when it is not NULL, we find the balance by substracting the right height val by the left height val
    */
   if (n == NULL){
        return 0;
   }
   else{
        return height(n -> left) - height(n -> right);
   }
}

void main(){
    struct node * root = NULL;
    //intializing the first node as NULL
    
    // making 24 the top of the bst
}



