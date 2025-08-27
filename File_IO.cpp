#include <iostream>
#include <fstream>
#include <chrono>
/*
This C++ program performs an I/O-bound benchmark by writing and reading a large number of integers to and from a file.
*/
int main() {
    const size_t N = 10'000'000; // number of integers
    const std::string filename = "io_test_c_plus_plus.txt";

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    // Write numbers to file
    std::ofstream outFile(filename);
    for (size_t i = 0; i < N; ++i) {
        outFile << i << "\n";
    }
    outFile.close();

    // Read numbers and sum them
    std::ifstream inFile(filename);
    long long sum = 0;
    size_t value;
    while (inFile >> value) {
        sum += value;
    }
    inFile.close();

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Output results
    std::cout << "C++: I/O-bound benchmark with " << N << " numbers took "
              << elapsed.count() << " seconds.\n";
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
