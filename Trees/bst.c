#include<stdio.h>
#include<stdlib.h>

//code rewritten from: https://www.codesdope.com/blog/article/binary-search-tree/

//some parts taken from github (mostly just intializations and )

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

NodeAddress arrayToReverseBST (int * a, int n){

    root = newinput(root, &a[0]);
    for(int i = 1; i < n; i++){
        newinput(root, &a[i]);
    }
    return root;
}

NodeAddress * newinput(struct node * root, int input){
    //if the root is NULL, then we place the new node 
    if (root == NULL){
        return new(input);
    }
    if (input > root -> val){
        root -> left = newinput(root -> left, input);
    }
    else{
        root -> right = newinput(root -> right, input);
    }
    return root;
    //calling itself recursively inorder to find the right place to input the new value
}

void main(){
    int array[7] = {22, 32, 1, 90, 4, 24, 15};
    arrayToReverseBST(array, 7);
    // making 24 the top of the bst
}

