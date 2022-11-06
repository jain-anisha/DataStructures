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
    struct nodeType * right; // big
};

// we're looking at a single node at a time
//from there, flow to left or right arrow

typedef struct nodeType * NodeAddress;

//assuming that someone created the structure for us
/*
we have char 4:
left child: 2
right: 7

2, left: 1, right: 3

7 left: 5, right 9

1,3,5,9 -> left: NULL; right: NULL

****moment you follow right child, you will find everything is greater...
than and vice versa

** Make sure every step you code is TESTABLE

*/

NodeAddress search(NodeAddress root, int val) {
    /*
    val is value being searched for 
    NodeAddress search is name of the func
    
    by looking things in the zoomed in version, we can be vv delicate and specific
    */
   if (root == NULL) return NULL;
   if       (val < root -> val) { search (root -> left, val);   }
   // recursively looking: if val is less than root -> val, then we will now go through the left tree
   else if  (val > root -> val) { search (root -> right, val);   }
   // otherwise, then we are going to right tree
   // we could hit NULL, which means val is not found in the list
   else return root //found the val!
}

NodeAddress search2(NodeAddress root, int val) {
    /*
    seeing that there is a lot of return statements in the first one, so we try to see if we can only return one

    trying to have one return statement so the code can be more elegant
    */
   return (val == root->val)? root: ( (val < root -> val) search2 (root -> left, val): search2 (root -> right, val) ); NULL;
}

NodeAddress insert(NodeAddress root, int val) {
    //now we are create node 

   if (root==NULL) {return createNode(val);};

   if       (val < root -> val) { insert (root -> left, val);   }
   // recursively looking: if val is less than root -> val, then we will now go through the left tree

   else if  (val > root -> val) { insert (root -> right, val);   }
   // otherwise, then we are going to right tree
   // we could hit NULL, which means val is not found in the list

   else                         {return root;} 
                                //found the val!
}