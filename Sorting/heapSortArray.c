#include<stdio.h>

void swap(int* x, int* y);
int heapify(int array[], int n, int start);
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

int heapify(int array[], int n, int start){
    int lChild, rChild, greatest;
    lChild = (2*start) + 1;                     //calculating the left & right child
    rChild = (2*start) + 2;
    greatest = start;                           //intializating the greatest element at the start element

    if(lChild < n && rChild < n){
        if(array[lChild] > array[greatest]){
            greatest = lChild;                  // storing the index point of the larger element btwn lChild and the root
        }
        if(array[rChild] > array[greatest]){
            greatest = rChild;                  //storing the index point of the larger element btwn the prev largest...
        }                                       //... element, and rChild
        //now we have three cases of the largest element: the original, lChild, and rChild. We will need to swap in all...
        //cases other than if the largest element found is the same as the original root. SO:
        if (greatest != start){
            swap(&array[greatest], &array[start]);
            //Now, we need to heapify the rest of the elements under the root
            heapify(array, n, greatest);
        }
    }
}

//int maxEle(int array[], int n){
void sort(int n, int array[]){
    //input: max heap
    //INV: i < n 
    //EXIT: when i = n
    int i = 0;
    for(i; i<n; i++){
        heapify(array, n, n/2 - 1);
    }

    for(i = n - 1; i<= n; i++){
        swap(&array[n], &array[0]);
        heapify(array, n, n/2);
    }

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
    sort(length, array);
    printf("The array is: ");                   //printing array
    for(i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}

// Seg fault...