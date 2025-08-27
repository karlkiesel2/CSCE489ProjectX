import time

def matmul_python(A, B):
    N = len(A)
    C = [[0.0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            s = 0.0
            for k in range(N):
                s += A[i][k] * B[k][j]
            C[i][j] = s
    return C

def main():
    N = 500  # same as C++
    A = [[1.0]*N for _ in range(N)]
    B = [[2.0]*N for _ in range(N)]

    start = time.time()
    C = matmul_python(A, B)
    end = time.time()

    print(f"Pure Python: {end - start:.4f} seconds")
    print(f"C[0][0] = {C[0][0]}")

if __name__ == "__main__":
    main()
