#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binSearch(int array[], int x, int n){
    int low = 0, mid, high = n - 1;
    while(low < high){
        mid = (low + high)/2;
        if(x <= array[mid])
            high = mid;
        else
            low = mid + 1;
    }
    if(array[high] == x)
        return array[high];
    else
        return -1;          //Do not know what to do with negative values in array
}

int main(){
    int array[] = {2, 10, 15, 27, 36, 41, 69, 78, 91, 100};
    int n = 10, x;
    scanf("%d", &x);
    printf("%d\n", binSearch(array, x, n));
}