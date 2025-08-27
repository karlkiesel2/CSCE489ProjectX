import time

def main():
    N = 10_000_000  # number of elements
    lst = []

    start = time.time()

    # Insert elements
    for i in range(N):
        lst.append(i)

    # Access all elements (sum them)
    total = 0
    for i in lst:
        total += i

    # Delete elements
    lst.clear()

    end = time.time()
    print(f"Python: Memory-bound benchmark with {N} elements took {end - start:.4f} seconds")
    print(f"Sum = {total}")

if __name__ == "__main__":
    main()
