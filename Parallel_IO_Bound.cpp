#include <iostream>
#include <fstream>
#include <thread>
#include <vector>
#include <chrono>

void write_and_read_file(int index, size_t N) {
    std::string filename = "file_" + std::to_string(index) + "_c_plus_plus.txt";

    // Write N integers to file
    std::ofstream out(filename);
    for (size_t i = 0; i < N; ++i) {
        out << i << "\n";
    }
    out.close();

    // Read file and sum values
    std::ifstream in(filename);
    long long sum = 0;
    size_t value;
    while (in >> value) {
        sum += value;
    }
    in.close();

    std::cout << "Thread " << index << " sum = " << sum << std::endl;
}

int main() {
    const int num_threads = 4;
    const size_t N = 2'500'000; // elements per thread (total ~10M)
    std::vector<std::thread> threads;

    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back(write_and_read_file, i, N);
    }

    for (auto& t : threads) t.join();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    std::cout << "C++: Parallel I/O benchmark with " << num_threads
              << " threads took " << elapsed.count() << " seconds.\n";

    return 0;
}
