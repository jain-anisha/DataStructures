#include<stdio.h>

void main()
{
    int x, y, temp;
    printf("This will swap the values of two integer variables. \n");
    printf("First number:");
    scanf("%d", &x);
    printf("\nSecond number:");
    scanf("%d", &y);
    temp = x;
    x = y;
    y = temp;
    printf("Now, x is %d, and y is %d", x, y);
}

//Edited to add for inputs
/* While doing this, found a segmentation fault error
- means that I was trying to access memory that "does not belong to me"
        - an "illegal" memory location
- also called a Core Dump
- The error occured because I did not add an '&' before x and y in the scanf functions
- This caused 
*/