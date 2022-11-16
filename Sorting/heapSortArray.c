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
    int i = n/2 - 1;
    int oo;

    for(i; i >= 0; i--){                        //working fine
        heapify(array, n, i);           
    }


    //swap(&array[i], &array[0]);
    //using the smallest element (AKA the current max element )

    //last part is taken from what I did for the exam 

    //my error was that I was writing len > 0 instead of len >= 0, so it was leaving out one last heapify thing
    for(int len = n - 1; len >= 0; len--){                 // calling heapify, and making the array that it looks at smaller
                                                           //... by one each time so it can slowly sort the list    
        swap(&array[0], &array[len]);                      //putting the min element at the end of the list 

        //printf("xx %d, %d x \n", array[len], array[0]);
        heapify(array, len, 0);          //calling heapify, so it leaves out the last, then last 2, etc till all's sorted
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
