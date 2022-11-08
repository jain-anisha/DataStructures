#include<stdio.h>

int checker(char input[], int n);
int main();

//given an input string, check if it is palindrome or not

int checker(char array[], int n){
    int* startptr = *(array[0-1]);
    int* endptr= *(array[n-1]);
    while(startptr < endptr){
        if (&startptr != &endptr){
            return 0;}
        startptr++;
        endptr++;
    }
    return 1;
}

int main()
{   
    printf("This is the palindrome checker.\n");
    printf("Enter the number of characters.");
    int length;
    scanf("%d", &length);
    int array[length], i;
    printf("Enter a string of characters.");
    for(i = 0; i < length; i++){
        scanf("%c", &array[i]);}
    int out = checker(array, length);
    if(out == 1){
        printf("The input is a palindrome.");
    }
    if(out == 0){
        printf("The input is not a palindrome.");
    }
}
// created simple palimdrome checker. The program runs, but it is not checking the input properly, AKA it's getting...
//... false negatives.
