#include <stdio.h>
#include <stdlib.h>

// prints all natural numbers before n

int main() {
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

// 