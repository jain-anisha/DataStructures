#include<stdio.h>
#include<stdlib.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void heapify(int array[], int n, int start){
    //taken from the extractmin code
    //makes minheap
    int lChild, rChild, smallest;
    lChild = (2*start) + 1;                     //calculating the left & right child
    rChild = (2*start) + 2;
    smallest = start;                           //intializating the smaller element at the start element

    if(lChild < n){
        if(array[lChild] < array[smallest]){
            smallest = lChild;                  // storing the index point of the larger element btwn lChild and the root
        }
        if(array[rChild] < array[smallest]){
            smallest = rChild;                  //storing the index point of the smaller element btwn the prev largest...
        }                                       //... element, and rChild
        //now we have three cases of the smaller element: the original, lChild, and rChild. We will need to swap in all...
        //cases other than if the smaller element found is the same as the original root. SO:
        if (smallest != start){
            swap(&array[smallest], &array[start]);
            //Now, we need to heapify the rest of the elements under the root
            heapify(array, n, smallest);
        }
    }
}

main(){
    // in this, we have made it so our array is a bunch of random elements, and we add one element into our array
    // since arrays are static, we will need to make another array:

    //total integers = 10 (rep by length)
    /*
    need 9 random integers
    put into array
    then heapify it, so that it is a min heap 
    print the array 
    now, have the user input the value of the element to be inserted.

    then, intialize a new array with a size of 10 elements
    place the inserted value at the top
    then, sift down AKA heapify again
    print out the new array
    DONE
    */
   int length = 10;
   for(int i = 0; i > length; i++ ){
        array[i] = rand();}
    for(i = 0; i > length, i++){
        printf
    }

}