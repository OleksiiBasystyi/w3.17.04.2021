#include <iostream>

int increment(int value, int inc=1) {
    return value + inc;
}

int main() {
    int x = 42;
    
    std::cout << increment(x) << std::endl;
    std::cout << increment(x, 10) << std::endl;
    
    return 0;
}
