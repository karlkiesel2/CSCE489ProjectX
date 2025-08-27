#include <iostream>
#include <vector>
#include <chrono>
/*
A simple memory-bound benchmark in C++ that performs insertions, accesses, and deletions on a vector.
*/
int main()
{
    // Number of elements to process
    const size_t N = 10'000'000;
    // Vector to hold the elements
    std::vector<int> vec;

    // Start timing
    auto start = std::chrono::high_resolution_clock::now();

    // Insert elements into the vector
    for (size_t i = 0; i < N; ++i)
    {
        vec.push_back(i);
    }

    // Access all elements (sum them)
    // max size of long long is 9,223,372,036,854,775,807, so plenty of room
    long long sum = 0;
    for (size_t i = 0; i < N; ++i)
    {
        sum += vec[i];
    }

    // Delete elements
    vec.clear();

    // End timing
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Output results
    std::cout << "C++: Memory-bound benchmark with " << N << " elements took "
              << elapsed.count() << " seconds.\n";
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
