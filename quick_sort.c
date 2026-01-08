// qsort sorts from array[left] to array[right] in increasing order
// Быстрая сортировка сортирует элементы массива в порядке возрастания начиная с array[left] до array[right]

void swap (int array[], int i, int j){
    int temp;
    temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void qsort(int array[], int left, int right){
    int i, last;
    
    if (left >= right)  //left is righter than right)
        return;
    swap(array, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if(array[i] < array[left])
            swap(array, ++last, i);
    swap(array, left, last);
    qsort(array, left, last - 1);
    qsort(array, last + 1, right);
}