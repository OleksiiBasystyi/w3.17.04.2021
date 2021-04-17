#include <iostream>

template<class T>
T increment (T value) {
    return value + 1;
}

int increment (int value) {
    return value + 100;
}

int main() {
    std::cout << increment(10) << std::endl;
    std::cout << increment<>(10) << std::endl;
    std::cout << increment('A') << std::endl;
    std::cout << increment(10.5) << std::endl;
    std::cout << increment((long)10) << std::endl;
        
    return 0;
}
