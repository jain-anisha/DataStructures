#include<stdio.h>
#include<stdlib.h>

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

NodeAddress new(int input){
    // mallocing space for a new node
    struct node * y = (struct node *)malloc(sizeof(struct node));
    // assigning values for the ptrs and val for the new node
    y -> val = input;
    y -> left = NULL;
    y -> right = NULL;
    return y;
    //returning the new node 
}


struct node * newinput(int input, NodeAddress root){
    //if the root is NULL, then we place the new node 
    if (root == NULL){
        return new(input);
    }
    if (input > root -> val){
        (root -> right) = newinput(input, root -> right);
    }
    else{
        (root -> left) = newinput(input, root -> left);
    }
    return root;
    //calling itself recursively inorder to find the right place to input the new value
}

NodeAddress arrayToReverseBST (int * a, int n){

    root = newinput( a[0], root);
    for(int i = 1; i < n; i++){
        newinput( a[i], root);
    }
    return root;
}

void printBST(struct node *root)
{
    // If the root node is NULL, return
    if (root == NULL)
        return;

    // print the left subtree.
    printBST(root->left);

    // Print val of the current node.
    printf("%d\n", root->val);

    //  print the right subtree.
    printBST(root->right);

    free(root);
}




void main(){
    
    int array[7] = {22, 32, 1, 90, 4, 24, 15};

    arrayToReverseBST(array, 7);
    printBST(root);


    // making 24 the top of the bst
}

//did something, now the code works, still figuring out why
// has something to do with naming conventions

