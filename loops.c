#include <stdio.h>
#include <stdlib.h>

// prints all natural numbers before n

/*int main() {
    int n = 0;
    printf("Input ending number:");
    scanf("%d", &n);
    int i;
    for(i = 1; i<n; ++i)
    {
        printf("%d ", i);
    }

    return 0;
}
*/

//Now writing a loop that gives the factorial

int main() {
    // need a counter and an input value
    // input stored in n, counter is i, previous product in p
    int n;
    int i = 1;
    int p = 1;
    printf("Input integer:");
    scanf("%d", &n);
    for (i; i < n; ++i)
    {
        p = p * i;
    }
    p = p * n;
    printf("The factorial of %d is %d", n, p);
    return 0;

}