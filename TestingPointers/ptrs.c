#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, k;
    int* ptrless;
    int* ptrbig;
    int** ptr2;
    for(i = 0; i < 10; i++){
        if(i < 5){
            ptrless = i;
        }
        else{
            ptrbig = i;
        }
        k = rand() % 2;
        if (k == 1){
            ptr2 = ptrless;
            printf("Less pointer's pointer is %d \n when i is %d.\n and random number is %d. \n", &ptr2, ptr2, k);
        }
        else{
            ptr2 = ptrbig;
            printf("Big pointer's pointer: %d \n when i is %d.\n and random number is %d. \n", &ptr2, ptr2, k);
        }
    }  
}