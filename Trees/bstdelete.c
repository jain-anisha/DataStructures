#include<stdio.h>
#include<stdlib.h>

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
NodeAddress search (int input);
NodeAddress delete (int value);
NodeAddress successor (NodeAddress node);

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

NodeAddress search (int input){
    if (root == NULL) {
        return root;
    }
    else if(input > root -> val){
        return search(root -> right);
    }
    else if(input < root -> val){
        return search(root -> left);
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
    NodeAddress node = search(value);

    if(node == NULL){
        return;
    }
    //can connect 2nd conditions to make it more simple

    if(node -> right == NULL){
        NodeAddress temp = node -> left;
        free(node);
    }
    if(node -> left == NULL){
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

    printf("Enter the values of the BST: ");
    scanf("%d \n", &data);

    root = new(data);        //intialization of the BST

    for(int i = 1; i < k - 1; i++){
        scanf("%d \n", &data);
        newinput(root, data);
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
    
    int k;
    printf("Enter total number of nodes in the BST: \n");
    scanf("%d", &k);

    arrayToBST(k);
    printBST(root);
    // making 24 the top of the bst
}
