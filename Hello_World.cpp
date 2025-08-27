#include <iostream>
#include <chrono>
/*
A simple C++ program that prints "Hello, World!" and measures execution time.
*/
int main() {
    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    // Print Hello, World!
    std::cout << "Hello, World!" << std::endl;

    // End timing and calculate execution time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> exec_time = end - start;
    std::cout << "Execution time: " << exec_time.count() << " ms" << std::endl;

    return 0;
}
