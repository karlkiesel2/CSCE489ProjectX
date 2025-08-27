import threading

def write_and_read_file(index, N):
    filename = f"file_{index}_python.txt"

    # Write N integers to file
    with open(filename, "w") as f:
        for i in range(N):
            f.write(f"{i}\n")

    # Read file and sum values
    total = 0
    with open(filename, "r") as f:
        for line in f:
            total += int(line.strip())

    print(f"Thread {index} sum = {total}")

def main():
    num_threads = 4
    N = 2_500_000  # elements per thread
    threads = []

    for i in range(num_threads):
        t = threading.Thread(target=write_and_read_file, args=(i, N))
        threads.append(t)
        t.start()

    for t in threads:
        t.join()

if __name__ == "__main__":
    main()
