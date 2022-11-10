#include<stdio.h>

void heapify(int array[], int n, int start);
void swap(int* x, int* y);

//CURRENT ERROR: The min heap code works. Having an issue with swapping the values of the elements, and then heapifying
// the array again.

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

int extractMin(int array[], int n){
    //input: an array
    int start = (n/2);
    printf("%d", array[n-1]);

    for(start; start >= 0; start--){ //makes min heap
        heapify(array, n, start);
    }                    
    //ERROR: specifically, the error is somewhere in here
    printf("min ele: %d\n", array[0]);  
    printf("last ele: %d\n", array[n-1]);   
    int x, y; 
    printf("%d", array[n-1]);
    swap(&array[0], &array[n-1]);                   //putting the min element at the end of the list
    printf("  %d  ", array[n-1]);

    start = (n/2);
    for(start; start >= 0; start--){ //makes min heap
        heapify(array, n-1, start);
    }                                               //heapifying again
    return 0;
}

void heapify(int array[], int n, int start){
    int lChild, rChild, smallest;
    lChild = (2*start) + 1;                     //calculating the left & right child
    rChild = (2*start) + 2;
    smallest = start;                           //intializating the greatest element at the start element

    if(lChild < n){
        if(array[lChild] < array[smallest]){
            smallest = lChild;                  // storing the index point of the larger element btwn lChild and the root
        }
        if(array[rChild] < array[smallest]){
            smallest = rChild;                  //storing the index point of the larger element btwn the prev largest...
        }                                       //... element, and rChild
        //now we have three cases of the largest element: the original, lChild, and rChild. We will need to swap in all...
        //cases other than if the largest element found is the same as the original root. SO:
        if (smallest != start){
            swap(&array[smallest], &array[start]);
            //Now, we need to heapify the rest of the elements under the root
            heapify(array, n, smallest);
        }
    }
}

int main()
{
    int length;
    printf("Enter number of elements in your list:");
    scanf("%d", &length);
    int array[length], i;                       // array w/ n # of elements 

    printf("Enter the %d elements to be sorted.\n", length);
    for (i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }
    int min = extractMin(array, length);

    printf("The array is: ");            //printing array
    for(i = 0; i<length-1; i++) {
        printf("%d ", array[i]);
    }
    //printf("The smallest element in the list is: %d", min);
    return 0;
}

//tried something with debugging the values, did not work
// next time, will try the assert method talked about in class