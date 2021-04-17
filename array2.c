#include <stdio.h>
#include <stdlib.h>

void arrayPrint(int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf("%d ", array[i]);
    }
    printf("%d\n", array[last]);
    
}

void arrayFill(int array[], int size) {
    for ( int i = 0; i < size; ++i) {
        array[i] = i;
    }
}

int main() {
    int *array = NULL;
    int *bkp;
    int len = 10;
    
    array = (int*)malloc(len*sizeof(int));
    arrayFill(array, len);
    arrayPrint(array, len);
    
    len = 15;
    bkp = array;
    array = (int*)realloc(array, len*sizeof(int));
    
    if ( array == NULL ) {
        array = bkp;
    }
    
    arrayFill(array, len);
    arrayPrint(array, len);
    
    free(array);
    
    return 0;
}
