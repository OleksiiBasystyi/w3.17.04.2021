/*
Условие задачи
void merge(int array[], int lo, int mid, int hi)
Слияние двух сортированных подмассивов в один отсортированный подмассив.
Первый подмассив от lo до mid не включая mid
Второй подмассив от mid до hi не включая hi
*/


#include <stdio.h>

#define LEN 10

void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int tmp[size];
    int i = lo;
    int j = mid;
    int k = 0;
    
    for ( ; i < mid && j < hi; k++ ) {
        if ( array[i] <= array[j] ) {
            tmp[k] = array[i];
            i += 1;
        } else {
            tmp[k] = array[j];
            j += 1;
        }
    }
    
    for ( ; i < mid; i++, k++ ) {
        tmp[k] = array[i];
    }
    
    for ( ; j < hi; j++, k++ ) {
        tmp[k] = array[j];
    }
    
    for ( int i = 0, j = lo; j < hi; i++, j++ ) {
        array[j] = tmp[i];
    }
}

void arrayPrint(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
}

void mergeSort(int array[], int start, int end) {
    int middle = ( start + end ) / 2;
    
    if ( start < middle ) {
        mergeSort(array, start, middle);
        mergeSort(array, middle, end);
        merge(array, start, middle, end);
    }
}

int main() {
    int array[LEN] = {10, 3, 7, 1, 6, 9, 2, 4, 8, 5};
    
    arrayPrint(array, LEN);
    
    mergeSort(array, 0, LEN);
    
    arrayPrint(array, LEN);
    
    return 0;
}
