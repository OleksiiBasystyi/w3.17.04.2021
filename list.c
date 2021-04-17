#include <stdio.h>

// LIFO sequence (stack)
struct Stack {
    struct Stack *prev;
    int value;
};

struct Stack *last = NULL;

int main() {
    struct Stack n1 = {NULL, 1};
    struct Stack n2 = {&n1, 2};
    struct Stack n3 = {&n2, 3};
    struct Stack n4 = {&n3, 4};
    
    last = &n4;
    
    for ( struct Stack *cur = last; ; cur = cur->prev ) {
        if ( cur->prev != NULL ) {
            printf("%d ", cur->value);
        } else {
            printf("%d\n", cur->value);
            break;
        }
    }
    
    return 0;
}
