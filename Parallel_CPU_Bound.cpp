#include <iostream>
#include <vector>
#include <thread>
#include <numeric>   // for std::accumulate
#include <chrono>

void partial_sum(const std::vector<int>& data, size_t start, size_t end, long long& result) {
    result = std::accumulate(data.begin() + start, data.begin() + end, 0LL);
}

int main() {
    const size_t N = 100'000'000; // size of array
    const int num_threads = 4;    // number of threads
    std::vector<int> data(N, 1);  // fill with ones
    std::vector<long long> results(num_threads, 0);

    std::vector<std::thread> threads;

    auto start_time = std::chrono::high_resolution_clock::now();

    size_t block_size = N / num_threads;
    for (int i = 0; i < num_threads; ++i) {
        size_t start = i * block_size;
        size_t end = (i == num_threads - 1) ? N : (i + 1) * block_size;
        threads.emplace_back(partial_sum, std::cref(data), start, end, std::ref(results[i]));
    }

    for (auto& t : threads) t.join();

    long long total_sum = 0;
    for (const auto& r : results) total_sum += r;

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << "C++: Parallel sum with " << num_threads << " threads took "
              << elapsed.count() << " seconds.\n";
    std::cout << "Total sum = " << total_sum << std::endl;

    return 0;
}
