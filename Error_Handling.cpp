#include <iostream>
#include <vector>
/*
Demonstrates basic error handling in C++ with try-catch blocks.
*/
int main() {
    // Here, we try division by zero, which will throw an exception.
    try {
        std::cout << "1. Division by zero:" << std::endl;
        int a = 10;
        int b = 0;
        int c = a / b;
        std::cout << "Result = " << c << std::endl;

    } catch (...) {
        std::cout << "Caught a divide-by-zero exception!" << std::endl;
    }

    std::cout << "\n2. Index out-of-bounds:" << std::endl;
    std::vector<int> vec = {1, 2, 3};
    // Here, we access an out-of-bounds index, which will throw an exception.
    try {
        // Using at() will throw, operator[] does not
        std::cout << vec.at(5) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range exception: " << e.what() << std::endl;
    }

    std::cout << "\n3. Null pointer access:" << std::endl;
    // Here, we dereference a null pointer, which leads to undefined behavior.
    try {
        int* ptr = nullptr;
        *ptr = 42;
        std::cout << *ptr << std::endl;
    } catch (...) {
        std::cout << "Caught exception on null pointer!" << std::endl;
    }

    return 0;
}
