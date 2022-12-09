#include <stdio.h> 
int main(void) { 
    int x = 65;
    printf("%i\n", x); // 65   
    // A represented by 65 in ascii
    printf("%c\n", (char) x); // A 6  
    //putting char in () to show that we are changing the cast

    x = -67;
    printf("%i\n", x); // 65 7
    
    printf("%c\n", (char) x); // C 6  

    printf("%d\n", (unsigned) x);
    }