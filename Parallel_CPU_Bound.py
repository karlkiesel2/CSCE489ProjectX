import multiprocessing as mp
import time

def partial_sum(start, end, data, out_queue):
    total = sum(data[start:end])
    out_queue.put(total)

def main():
    N = 100_000_000
    num_processes = 4
    data = [1] * N

    block_size = N // num_processes
    out_queue = mp.Queue()
    processes = []

    start_time = time.time()

    for i in range(num_processes):
        start = i * block_size
        end = N if i == num_processes - 1 else (i + 1) * block_size
        p = mp.Process(target=partial_sum, args=(start, end, data, out_queue))
        processes.append(p)
        p.start()

    for p in processes:
        p.join()

    total_sum = 0
    while not out_queue.empty():
        total_sum += out_queue.get()

    end_time = time.time()
    print(f"Python (multiprocessing) sum with {num_processes} processes took {end_time - start_time:.4f} seconds")
    print(f"Total sum = {total_sum}")

if __name__ == "__main__":
    main()
