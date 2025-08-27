import time
'''
This Python program performs a CPU-bound benchmark by multiplying two large matrices.
'''

# This function multiplies two matrices A and B of size N x N
def matmul_python(A, B):
    N = len(A)
    # C is a 2D list initialized to zero
    C = [[0.0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            # Compute the dot product of row i of A and column j of B
            s = 0.0
            for k in range(N):
                s += A[i][k] * B[k][j]
            # store the result in C
            C[i][j] = s
    return C

def main():
    N = 500
    A = [[1.0]*N for _ in range(N)]
    B = [[2.0]*N for _ in range(N)]

    # Start timing, perform multiplication, and end timing
    start = time.time()
    C = matmul_python(A, B)
    end = time.time()

    # Output results
    print(f"Pure Python: {end - start:.4f} seconds")
    print(f"C[0][0] = {C[0][0]}")

if __name__ == "__main__":
    main()
