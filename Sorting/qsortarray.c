#include<stdio.h>

void swap(int* x, int* y);
int partition(int start, int stop, int array[]);
void Qsort(int start, int stop, int array[]);

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

int partition(int start, int stop, int array[])
// takes in array and divides it into two greater and lesser lists
{   
    // we need to have a 
    int i, j, pivot;       // lesser & greater walls

    i = start + 1;
    j = stop;
    pivot = array[start];
    while(i <= j){
        if (array[i] > pivot){
            swap(&array[i], &array[j]);   
            j--;
        }
        else {
            i++;
        }
        }
    swap(&array[start], &array[j]);
    return j;                               // giving back the 
}

void Qsort(int start, int stop, int array[]){
    if (start > stop){
        return;
    }
    // need to sort both sides of the list
    int wall = partition(start, stop, array);     //Returns pivot val
    Qsort(start, wall - 1, array);                        // LESSER
    Qsort(wall + 1, stop, array);                         // GREATER
}

int main()
{
    /* code */
    int length;
    printf("Enter number of elements in your list:");
    scanf("%d", &length);
    //printf("%d", n);      check to see if storing properly
    int array[length];                       // array w/ n # of elements    
    int i;
    printf("Enter the %d elements to be sorted.\n", length);
    for (i = 0; i < length; i++){
        scanf("%d", &array[i]);
    }
    Qsort(0, length - 1, array);
    int ix;
    printf("The array is:");            //printing array
    for(ix = 0; ix<length; ix++) {
        printf("%d ", array[ix]);
    }
    return 0;
}

// In this, I mainly had syntax errors while writing it.
// printing 