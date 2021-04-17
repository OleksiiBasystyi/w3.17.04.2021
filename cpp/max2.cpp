#include <iostream>

int main() {
    int x, y;
    
    std::cin >> x;
    std::cin >> y;
    
    if ( x > y ) {
        std::cout << x << std::endl;
    } else {
        std::cout << y << std::endl;
    }
    
    return 0;
}
