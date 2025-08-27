import time

def main():
    N = 10_000_000
    filename = "io_test_python.txt"

    start = time.time()

    # Write numbers to file
    with open(filename, "w") as f:
        for i in range(N):
            f.write(f"{i}\n")

    # Read numbers and sum them
    total = 0
    with open(filename, "r") as f:
        for line in f:
            total += int(line.strip())

    end = time.time()

    print(f"Python: I/O-bound benchmark with {N} numbers took {end - start:.4f} seconds")
    print(f"Sum = {total}")

if __name__ == "__main__":
    main()
