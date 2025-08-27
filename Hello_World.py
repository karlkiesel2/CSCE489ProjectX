'''
# Hello World program with execution time measurement'''
import time
# Start timing
start_time = time.time()
# Print Hello, World!
print("Hello, World!")
# End timing and calculate execution time
end_time = time.time()
exec_time = (end_time - start_time) * 1000  # milliseconds
print(f"Execution time: {exec_time} ms")