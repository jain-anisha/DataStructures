#include <stdio.h>

int j, k;
int *ptr;

int main(void)
{
    j = 1;
    k = 2;
    ptr = &k;
    printf("\n");
    printf("j has the value %d and is stored at %p\n", j, (void *)&j);
    printf("k has the value %d and is stored at %p\n", k, (void *)&k);
    printf("ptr has the value %p and is stored at %p\n", ptr, (void *)&ptr);
    printf("The value of the integer pointed to by ptr is %d\n", *ptr);

    return 0;  

}

int my_array[] = {1,23,17,4,-5,100};
int *ptrtwo;

int mai(void) 
{
    int i;     
    ptrtwo = &my_array[0];     /* point our pointer to the first                                       
                            element of the array */     
    printf("\n\n");     
    for (i = 0; i < 6; i++)     
    {       
        printf("my_array[%d] = %d   ",i,my_array[i]);   /*<-- A */       
        printf("ptrtwo + %d = %d\n",i, *(ptrtwo + i));        /*<-- B */     
    }     
    return 0;
} 