#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    
    array = malloc(LEN*sizeof(int));
    
    for ( unsigned long long i = 0; i < LEN; i++ ) {
        array[i] = 0;
    }
    
    printf("%d\n", array[LEN-1]);
    
    return 0;
}
