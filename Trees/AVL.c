#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//just need to figure out how to print it

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

int balanceVal(struct node * n);
struct node *leftRotate(int k, struct node * node1);
struct node *rightRotate(int k, struct node * node2);
int height(struct node *node);
int greater(int one, int two);
// we're looking at a single node at a time
//from there, flow38 to left or right arrow

typedef struct node * NodeAddress;

struct node * root = NULL;

int height(struct node *node)
{
    if (node == NULL)
        return 0;
    return node -> height;
    //returns height of a node
}

int greater(int one, int two){          //returns greater element
    if (one > two) {return one; }
    else {return two;}
}

NodeAddress new(int input){
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

NodeAddress newinput(struct node * node, int input){
    //if the root is NULL, then we place the new node 
    if (node == NULL){
        return new(input);
        // found the current leaf, inserting the node here
    }
    //three cases: input greater than root, input less than root, or the input is the root
    if (input < node -> val){
        node -> left = newinput(node -> left, input);
    }
    else if (input > root -> val){
        node -> right = newinput(node -> right, input);
    }
    else{
        return node;
    }

    //update the height
    
    node -> height = greater(height(node -> right), height(node -> left)) + 1;

    //calling itself recursively inorder to find the right place to input the new value
    int bal = balanceVal(node);
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
        if(input < node -> left -> val){                //left left 
            return rightRotate(0, node);
        }
        else if(input > node -> left -> val){           //left right
            root -> left = leftRotate(0, node -> left);
            return rightRotate(0, node);
        }
    }
    else if (bal < -1){
        if(input > node -> right -> val){               //right right
            return leftRotate(0, node);
        }
        else if(input < node -> right -> val){          //right left
            node -> right = rightRotate(0, node -> right);
            return leftRotate(0, node);
        }
    }
   return node;
}

struct node *leftRotate(int k, struct node * node1){
    /*new top is node1 -> right
    newTop's left root swaps to the other node
    */
    printf("left rotate \n");

    struct node * newTop = node1 -> right;
    struct node * swapRoot = newTop -> left;
    newTop -> left = node1;
    node1 -> right = swapRoot;

    //updating node1 height
    node1 -> height = greater(height(node1 -> right), height(node1 -> left)) + 1;

    newTop -> height = greater(height(newTop -> right), height(newTop -> left)) + 1;


    return newTop;
}

struct node *rightRotate(int k, struct node * node2){
    /*new top is node2 -> left
    newTop's right root swaps to the other node
    */
    printf("right rotate \n");

    struct node * newTop = node2 -> left;
    struct node * swapRoot = newTop -> right;
    newTop -> right = node2;
    node2 -> left = swapRoot;

    //updating heights of the nodes
    node2 -> height = greater(height(node2 -> right), height(node2 -> left)) + 1;

    newTop -> height = greater(height(newTop -> right), height(newTop -> left)) + 1;

    return newTop;

}


int balanceVal (struct node * n){
 
    /*in order to balance a tree, need to know the weights of both sides of the tree

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


void printBST(struct node *root)
{
    // If the root node is NULL, return
    if (root == NULL)
        return;
    // print the left subtree.
    printBST(root->left);
    printf("-> %d\n", root->val);

    // Print val of the current node.

    //  print the right subtree.
    printBST(root->right);

    //printf(" not %d\n", root->val);

    //free(root);
}

NodeAddress arrayToBST (int k){
    int data;           //stores inputted value of the BST node

    printf("Enter the values of the BST: ");
    scanf("%d \n", &data);

    root = newinput(root, data);        //intialization of the BST

    for(int i = 1; i < k - 1; i++){
        scanf("%d \n", &data);
        newinput(root, data);
    }
    return root;
}

void main(){

    //intializing the first node as NULL
    
    int k;
    printf("Enter total number of nodes in the BST: \n");
    scanf("%d", &k);

    root = arrayToBST(k);
    printBST(root);
    // making 24 the top of the bst
}



