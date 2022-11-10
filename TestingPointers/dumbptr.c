#include<stdio.h>

int main(){
    int i;
    int z = 0;
    int sum = 0;
    for(i=0; i-=1000; i++){
        sum = sum + i;
        z++;
    }
    printf("%d takes %d loops when i is %d", sum, z, i);
    return 0;
}

//overflows: after being a very negative number, the number shifts to being 0, bc of how two's complement works