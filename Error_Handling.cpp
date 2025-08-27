#include <iostream>
#include <vector>

int main() {
    try {
        std::cout << "1. Division by zero:" << std::endl;
        int a = 10;
        int b = 0;
        int c = a / b;  // Undefined behavior in C++
        std::cout << "Result = " << c << std::endl;

    } catch (...) {
        std::cout << "Caught an exception!" << std::endl;
    }

    std::cout << "\n2. Index out-of-bounds:" << std::endl;
    std::vector<int> vec = {1, 2, 3};
    try {
        // Using at() will throw, operator[] does not
        std::cout << vec.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range exception: " << e.what() << std::endl;
    }

    std::cout << "\n3. Null pointer access:" << std::endl;
    try {
        int* ptr = nullptr;
        *ptr = 42;  // Undefined behavior, may crash
        std::cout << *ptr << std::endl;
    } catch (...) {
        std::cout << "Caught exception on null pointer!" << std::endl;
    }

    return 0;
}
