#include <stdio.h>
#include <stdlib.h>

// LIFO sequence (stack)
struct Stack {
    struct Stack *prev;
    int value;
};

struct Stack *stack_last = NULL;

void stack_append(int value) {
    struct Stack *elem = (struct Stack*)malloc(sizeof(struct Stack));
    
    if ( stack_last != NULL ) {
        elem->prev = stack_last;
    } else {
        elem->prev = NULL;
    }
    
    elem->value = value;
    stack_last = elem;
    
}

void print_stack() {
    for ( struct Stack *cur = stack_last; ; cur = cur->prev ) {
        if ( cur->prev != NULL ) {
            printf("%d ", cur->value);
        } else {
            printf("%d\n", cur->value);
            break;
        }
    }
}

int main() {
    stack_append(1);
    stack_append(2);
    stack_append(3);
    
    print_stack();
    
    return 0;
}
