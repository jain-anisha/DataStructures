// for an array

#include<stdio.h>
#include<stdlib.h>
void selectionSort(int n, int array[]);
void swap(int* x, int* y);

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

void selectionSort(int n, int array[])
{
    int j, i, minNum, c;
    for (i = 1; i < n - 1; i = i + 2) {
        minNum = array[i];                  //take the first element of the unsorted list to be the minNum
        for (j = i + 2; j < n; j = j + 2){      // by jumping up 2, we only check every second element in the array   
            if (minNum > array[j]){         
                minNum = array[j];
                swap(&array[i], &array[j]);
            }
        }
}
}

int main()
{
    /* code */
    int n;
    printf("Enter number of elements in your list:");
    scanf("%d", &n);
    //printf("%d", n);      check to see if storing properly
    int array[n];           // array w/ n # of elements
    /*
    writing a loop
    need to allocate space for n integers*/
    int i;
    printf("Enter the %d elements to be sorted.\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    selectionSort(n, array);
    int ix;
    printf("The array is:");
    for(ix = 0; ix<n; ix++) {
        printf("%d ", array[ix]);
    }
    return 0;
}
// Debugged. Found an error for memory, fixed it by seeing that it was accessing memory not alocated to it & the selection sort algo...
// ... was not swapping properly, since it needed an integer, and I was giving it an index element