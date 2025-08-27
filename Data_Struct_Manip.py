import time
''' A simple memory-bound benchmark in Python that performs insertions, accesses, and deletions on a vector.'''
def main():
    # Number of elements
    N = 10_000_000
    # Initialize list to hold elements
    lst = []

    # Start timing
    start = time.time()

    # Insert elements
    for i in range(N):
        lst.append(i)

    # Access all elements (sum them)
    # Note: we do not need to worry about the sum being too large for the total variable
    total = 0
    for i in lst:
        total += i

    # Delete elements
    lst.clear()

    # End timing
    end = time.time()
    print(f"Python: Memory-bound benchmark with {N} elements took {end - start:.4f} seconds")
    print(f"Sum = {total}")

# Run the benchmark
if __name__ == "__main__":
    main()
