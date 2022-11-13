#include<stdio.h>
/*
When making searching through a linked list, going char by char is linear time
AKA it's too slow
There are a few ways to get around that
ONE: Binary Search
*/

struct nodeType {
    int val;
    struct nodeType * left; //smaller branch
    struct nodeType * right; // bigger
};

// we're looking at a single node at a time
//from there, flow to left or right arrow

typedef struct nodeType * NodeAddress;

NodeAddress search(NodeAddress root, int val){
    if (root == NULL) return NULL;
    /*
    items less than the root will be to the left child
    items greater than the root will be the right child
    */

    if (val < root -> val) {
        search (root -> left, val);
    }
    else if (val > root -> val) {
        search (root -> right, val);
    }
    else return root;
}

void main(){
    
}

