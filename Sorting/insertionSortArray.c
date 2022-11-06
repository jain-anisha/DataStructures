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
    if(!array || n < 2){
        printf("Invalid input.");
        return -1;
        }                        //checking for valid input 
    for(i = 1; i < n; i++){

            j = i - 1;
            point = array[i];
            while(point <= array[j] && j >= 0){ 
                //swap(&array[point], &array[j]);
                // printf("%d;;%d", point1, point2);
                array[j + 1] = array[j];
                j--;
        }
        array[j + 1] = point;
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