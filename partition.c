/*
Условие задачи
int partition(int array[], int start, int end)

В качестве опорного элемента брать среднее арифметическое между start и end с округлением вниз.
*/

#include <stdio.h>

#define LEN 10

int partition(int array[], int start, int end) {
    int tmp = (start + end) / 2;
    int target = array[tmp];
    int tail = start;
    
    array[tmp] = array[end];
    array[end] = target;
    
    for ( ; array[tail] < array[end]; tail++ );
    for ( int i = tail + 1; i < end; i++ ) {
        if ( array[i] < array[end] ) {
            tmp = array[i];
            array[i] = array[tail];
            array[tail] = tmp;
            tail += 1;
        }
    }
    
    tmp = array[end];
    array[end] = array[tail];
    array[tail] = tmp;
    
    return tail;
}

void arrayPrint(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
}

void quickSort (int array[], int start, int end) {
    int index;
    
    if ( end - start > 0 ) {
        index = partition(array, start, end);
        
        quickSort(array, start, index - 1);
        quickSort(array, index + 1, end);
    }
}

int main() {
    int array[LEN] = {10, 3, 7, 1, 6, 9, 2, 4, 8, 5};
    arrayPrint(array, LEN);
    
    quickSort(array, 0, LEN-1);
    
    arrayPrint(array, LEN);
    
    return 0;
}
