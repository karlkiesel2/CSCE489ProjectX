#include <iostream>
#include <vector>
#include <chrono>
/*
This C++ program performs a CPU-bound benchmark by multiplying two large matrices.
*/
// This function multiplies two matrices A and B of size N x N
void multiplyMatrices(const std::vector<std::vector<double>> &A,
                      const std::vector<std::vector<double>> &B,
                      std::vector<std::vector<double>> &C, int N)
{

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            // Compute the dot product of row i of A and column j of B
            double sum = 0.0;
            for (int k = 0; k < N; ++k)
            {
                sum += A[i][k] * B[k][j];
            }
            // store the result in C
            C[i][j] = sum;
        }
    }
}

int main()
{
    // Create two N x N matrices filled with sample data and a result matrix
    int N = 500;
    std::vector<std::vector<double>> A(N, std::vector<double>(N, 1.0));
    std::vector<std::vector<double>> B(N, std::vector<double>(N, 2.0));
    std::vector<std::vector<double>> C(N, std::vector<double>(N, 0.0));

    // start timing, perform multiplication, and end timing
    auto start = std::chrono::high_resolution_clock::now();
    multiplyMatrices(A, B, C, N);
    auto end = std::chrono::high_resolution_clock::now();

    // Output results
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "C++: Matrix multiplication of size " << N << "x" << N
              << " took " << elapsed.count() << " seconds.\n";
    std::cout << "C[0][0] = " << C[0][0] << std::endl;

    return 0;
}
