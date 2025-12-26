void shellsort(int arrayInt[], int arrayLength){
    int gap, i, j, temp;
    for(gap = arrayLength/2; gap > 0; gap /= 2){
        for(i = gap; i < arrayLength; ++i){
            for(j = i-gap; j >= 0 && arrayInt[j] > arrayInt[j+gap]; j -= gap){
                temp = arrayInt[j];
                arrayInt[j] = arrayInt[j+gap];
                arrayInt[j+gap] = temp;
            }
        }
    }
}

// array = [4, 7, 1, 0, 3, 5], n = 6
// gap = 3, i = 3, j = 0 => array = [0, 7, 1, 4, 3, 5]
// gap = 3, i = 4, j = 1 => array = [0, 3, 1, 4, 7, 5]
