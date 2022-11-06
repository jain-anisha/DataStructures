int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


// Qsort(a, 0, n-1)
// a is the name of the array

void qsort(int* a, int start, int stop){
    if (!a|| start > stop) return;    // checking for good inputs
        // not >= bc then the array is length of one, where sorting is not necessary
    int p = partition( a, start, stop);
        // putting the parition of the array into another func
    qsort(a, start, p - 1);
        // sorts the lesser part
    qsort(a, p+1, stop);
        // sorts the greater part
    
        // just by this, if partition works, then we would have a proper list
}

// for the partition part:

r = rand(start, stop);  // picking an element at random btwn start and stop
swap(a, start, r);

int partition (int* a, int start, int stop){
    // declaring all variables
    // start is the first element, that will use as the pivot element
    pivot = a[start];
    // say that start = 14
    //spliting into two
    i = start + 1;
    // pointing to location right next to start
    // left than i? less than/equal to pivot
    j = stop;       //nothing here at this point
    // right of j? greater than pivot

    while(i <= j   ){
        if (a[i] > pivot){
            swap (a, i, j);
            // swapping the two elements
            j = j - 1;
            // changing the stop wall to the element just next to j
        }
        else{
            i++;
        }
        //will come a point where i = j
        // cannot stop here, since we do not know what the value of this element is
        // so need to wait until i is greater to j
    }
    // now, to put pivot at the right spot, we simply swap the pivot(AKA start) with j
    swap(a, start, j)
    return j; //giving the prev pivot val


}
*/