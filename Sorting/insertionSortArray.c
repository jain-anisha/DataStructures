#include<stdio.h>

void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    // swapping places of two different values
}

int insertsort(int array[], int n){
    int i, j, point;
    // i = index
    // j = place of last sorted element
    // n = number of elements in array
    // point = point of comparsion
    // INV: i <= n; j <= n; point <= n
    if(!array || n <= 1){
        return;
        }                        //checking for valid input 
    i, point = 0;
    j = 1;

    while(i <= n){
        if(array[i] <= array[j]){
            j++;
            i++;
        }
        else{
            swap(&array[i], &array[j]);
            point++;
            if(array[point] > array[j]){
                swap(&array[point], &array[j]);
            }

        }
    }
}
// implemented sort with the wrong type of loop, so essentially need to keep in mind the loops for...
// the next time around

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
    printf("The array is:");            //printing array
    for(i = 0; i<length; i++) {
        printf("%d ", array[i]);
    }
    return 0;
}