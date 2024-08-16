import os
import time
import random
total_excution_start=time.process_time()
def mat_mul(A, B,C, n):
    for i in range(n):
        for j in range(n):
            C[i][j] = sum(A[i][k] * B[k][j] for k in range(n))
    return C

def measure_time(n, dtype):
    print(f"Calculating the User time and System time for matrix multiplication ({dtype}):-\n")
    # Measure User and System time
    for i in range(1):
        start_times = os.times()
        if dtype == 'int':
            A = [[random.randint(1, 100) for _ in range(n)] for _ in range(n)]
            B = [[random.randint(1, 100) for _ in range(n)] for _ in range(n)]
        else:
            A = [[random.uniform(1.0, 100.0) for _ in range(n)] for _ in range(n)]
            B = [[random.uniform(1.0, 100.0) for _ in range(n)] for _ in range(n)]  
        C = [[0] * n for _ in range(n)]
        user_time_accum = 0
        sys_time_accum = 0
        meat_time_start=time.process_time()
        C = mat_mul(A, B,C, n)
        meat_time_end=time.process_time()
        print(f"Time taken by the program on {dtype} values of size {n} is: "
              f"{meat_time_end-meat_time_start} seconds")
        print("\n")

# n_values = [64, 128, 256, 512, 1024]

measure_time(1024, 'double')
total_excution_end=time.process_time()
print(f"Total time taken by the program is: {total_excution_end-total_excution_start} seconds")