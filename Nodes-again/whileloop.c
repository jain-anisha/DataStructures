#include <stdio.h>

// @brief 
int main()
{
    int i = 0;

    while (i < 10)
    {
        printf("%d and %d: ", i, i + 2);
        i++;
    }
    return 0;
}