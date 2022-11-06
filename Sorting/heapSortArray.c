#include<stdio.h>

void swap(int* x, int* y);
void heapify(int array[], int n);
void sort(int n, int array[]);

//representing a heap in an array
//not creating a data structure specifically for heaps, since left & right child can be found by formulas

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

void heapify(int array[], int n){
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
        while(&array[lChild] != NULL ){     //checking if root has children
                                            //EDIT: this step is not necessary, since all the elements p = n/2...
                                            //.. has a child out of the definition of p = n/2
            lChild = (2*j) + 1;
            rChild = (2*j) + 2;
            if (&array[j] < &array[rChild]){
                swap(&array[j], &array[rChild]);
            }
            if (&array[j] < &array[lChild]){
                swap(&array[j], &array[lChild]);
            //ERROR: I am not going through the heap properly
            //In this case, i am still going through the heap without necessity, so need to find a way to go through it

            }
        }
    }

//int maxEle(int array[], int n){
void sort(int n, int array[]){

}

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
    heapify(array, length);
    printf("The array is: ");                   //printing array
    for(i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    return 0;


}

// Seg fault...