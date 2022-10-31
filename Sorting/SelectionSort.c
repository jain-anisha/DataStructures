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
    for (i = 0; i < n - 1; i++) {
        minNum = array[i];
        for (j = i + 1; j < n; j++){
            if (minNum > array[j]){
                minNum = array[j];
                c++;
            if (c!=0)
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
// essentially got the sorting algo, just debugging the printing of the array