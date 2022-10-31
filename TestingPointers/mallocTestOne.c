#include <stdio.h>
#include <stdlib.h>

int main () {
    int *a;
    int y;
    // this is an integer, it is expecting an integer
    a = malloc(1000 * sizeof(int));
    // a is just an address, that stores the location of 
    // this just allocates space in memory
    //if not careful of number of space in malloc, bad things happen
    printf("value of y is %d originally \n", a);
    y = *(a + 1);
    printf("Now, value of y is %d", y);
    /* this will go to the address of the next integer, which would be the next 4 bites */
   
   return 0;
}