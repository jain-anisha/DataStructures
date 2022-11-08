#include <stdio.h>

int my_array[] = {1,23,17,4,-5,100}; 
int *ptrtwo;

int main() 
{
    int i;     
    ptrtwo = &my_array[0];     /* point our pointer to the first element of the array */     

    printf("\n\n");     
    for (i = 0; i < 6; i++)     
    {       
        printf("my_array[%d] = %d   ",i,my_array[i]);   /*<-- A */       
        printf("ptrtwo + %d = %d\n",i, *(ptrtwo + i));  /*<-- B */     
    }     
    return 0;
} 