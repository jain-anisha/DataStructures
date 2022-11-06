#include<stdio.h>

void swap(int* x, int* y);
void insertsort(int array[], int n);
int main();

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

void insertsort(int array[], int n){
    int i, j, point;
    // i = index
    // j = place of last sorted element
    // n = number of elements in array
    // point = point of comparsion
    // INV: i <= n; j <= n; point <= n
    if(!array || n < 2){
        printf("Invalid input.");
        return;
        }                        //checking for valid input 
    for(i = 1; i < n; i++){

            j = i - 1;          //making this the start of the sorted list
            while(array[j] > array[j+1] && j >= 0){ 
                swap(&array[j+1], &array[j]);       //swap func
                j--;                                // decreases by one, in order continue to compare the values so 
                                                    // the current val at array[j+1] is put at the right location
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
    insertsort(array, length);
    printf("The array is: ");            //printing array
    for(i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}