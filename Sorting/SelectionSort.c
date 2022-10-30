#include<stdio.h>
#include<stdlib.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

void selectionSort(int n, int array[]){
    int minNum, j, i;

    for (i = 0; i < n - 1; i++) {
        minNum = i;
        for(j = i + 1; i < n - 1; j++){
            if (array[j] < array[minNum]){
                minNum = j;
            }
            if (minNum != i){
                swap( &array[minNum], &array[i]);
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
    int array[n];
    /*
    writing a loop
    need to allocate space for n integers*/
    int i = 0;
    for (i; i < n; i++){
        printf("Enter Number %d", i);
        scanf("%d", &array[i]);
    }
    selectionSort(n, array);
    for(int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}
// essentially got the sorting algo, just debugging the printing of the array