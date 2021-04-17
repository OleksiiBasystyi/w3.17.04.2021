#include <stdio.h>

int main() {
    int x, y;
    int max;
    
    scanf("%d %d", &x, &y);
    
    max = x;
    if ( y > max ) {
        max = y;
    }
    
    printf("%d\n", max);
    
    return 0;
}
