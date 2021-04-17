#include <iostream>

int increment(int value) {
    return value + 1;
}

char increment(char value) {
    return value + 1;
}

double increment(double value) {
    return value + 1;
}

long increment(long value) {
    return value + 2;
}

int main() {
    std::cout << increment(10) << std::endl;
    std::cout << increment('A') << std::endl;
    std::cout << increment(10.4) << std::endl;
    std::cout << increment(10L) << std::endl;
    
    return 0;
}
