#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int capacity;
    int current;
    int *array;
} Vector;

void init(Vector *vector, int capacity) {
    vector->capacity = capacity;
    vector->current = 0;
    vector->array = (int*)malloc(capacity*sizeof(int));
}

void kill(Vector *vector) {
    vector->capacity = 0;
    vector->current = 0;
    free(vector->array);
}

void push_back(Vector *vector, int value) {
    if ( vector->current == vector->capacity ) {
        int newCapacity = vector->capacity * 1.5;
        int *newArray = (int*)realloc(vector->array, newCapacity*sizeof(int));
        
        if ( newArray == NULL ) {
            return;
        }
        
        vector->capacity = newCapacity;
        vector->array = newArray;
    }
    
    vector->array[vector->current] = value;
    vector->current += 1;
}

void vector_print(Vector *vector) {
    int last = vector->current - 1;
    
    if ( last < 0 ) {
        printf("Vector is empty!\n");
        return;
    }
    
    printf("[");
    for ( int i = 0; i < last; i++ ) {
        printf("%d, ", vector->array[i]);
    }
    printf("%d]\n", vector->array[last]);
}

int main() {
    Vector vector;
    
    init(&vector, 10);
    vector_print(&vector);
    for (int i = 0; i < 10; i++ ) {
        push_back(&vector, i);
    }
    push_back(&vector, 90);
    push_back(&vector, 91);
    push_back(&vector, 92);
    vector_print(&vector);   
    
    kill(&vector); 
    
    return 0;
}
