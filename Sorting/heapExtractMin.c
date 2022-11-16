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
    //printf("%d", array[n-1]);

    for(start; start >= 0; start--){ //makes min heap
        heapify(array, n, start);
    }                    

    //ERROR: specifically, the error is somewhere in here
    return array[0];
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
    printf("Enter number of elements in your list: ");
    scanf("%d", &length);
    int array[length], i;                       // array w/ n # of elements 

    printf("Enter the %d elements to be sorted.\n", length);
    for (i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }
    int min = extractMin(array, length);

    printf("The smallest element in the list is: %d", min);
    return 0;
}

// found the error: I was thinking too much: all I had to do is make a min heap and print the first number in the new heap