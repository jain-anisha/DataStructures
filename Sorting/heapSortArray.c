#include<stdio.h>

void swap(int* x, int* y);
void heap(int array[], int n);

//representing a heap in an array
//not creating a data structure specifically for heaps, since left & right child can be found by formulas

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

void heap(int array[], int n){
    int lChild, rChild, p, j, i;
    // first, need to find the index of the element where we start the heap
    //lChild = (2*p) + 1;
    //rChild = (2*p) + 2;
    //ABOVE WRITTEN FOR NOTES

    //need to traverse the list
    /*Intializations: 
    i = counter
    lChild, rChild: left and right child
    need to have it so that i is greater than lChild and rChild
    EXIT CONDITION: when i = 0, we stop
    INV: i <= p; i > 0 
    */
    p = n/2;                                // starting at the first elements in the second to last row
    for(i = p; i = 0; i--){
        j = i;
        lChild = (2*i) + 1;
        }
        while(&array[lChild] != NULL ){
            lChild = (2*j) + 1;
            rChild = (2*j) + 2;
            if (array[j] < array[rChild]){
                swap(&array[j], &array[rChild]);
            }
            if (array[j] < array[lChild]){
                swap(&array[j], &array[lChild]);
            }
        }


    }

//int maxEle(int array[], int n){

int main(){
    // taken from prev sorting
    int length;
    printf("Enter number of elements in your list:");
    scanf("%d", &length);
    int array[length], i;                       // array w/ n # of elements 
    printf("Enter the %d elements to be sorted.\n", length);
    for (i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }
    heap(array, length);
    printf("The array is: ");                   //printing array
    for(i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    return 0;


}

// Seg fault...