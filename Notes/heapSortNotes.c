// way of listing data, so that there is a limit on each layer

// why do we input int* a? and not just the array[]?

void sort(int * a, int n){
    for (i =0; i <n; i ++){
        p = findMaxPos(a, n - i);           //n is one greater than the last index pos
                                            // so as we increase from one place to another 
        swap(a, n - i);
        // each time, giving last element remain:
        // so: first time: n-1
        /* 2nd: n - 2
        3rd: n - 3
        etc... which is why we have n - 1 - i
        */
    }
}

// to make a heap
/*
Say we have the array:
[88, 99, 4, 42, 11, 35, 57, 3, 49, 69, 73, 20]
We sort it:
[99, 88, 73, 69, 57, 49, 42, 35, 20, 11, 4, 3]
and puts it in the 
*/