#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const size_t N = 10'000'000; // number of elements
    std::vector<int> vec;

    auto start = std::chrono::high_resolution_clock::now();

    // Insert elements
    for (size_t i = 0; i < N; ++i) {
        vec.push_back(i);
    }

    // Access all elements (sum them)
    long long sum = 0;
    for (size_t i = 0; i < N; ++i) {
        sum += vec[i];
    }

    // Delete elements
    vec.clear();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "C++: Memory-bound benchmark with " << N << " elements took "
              << elapsed.count() << " seconds.\n";
    std::cout << "Sum = " << sum << std::endl;

    return 0;
}
