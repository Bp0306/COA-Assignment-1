import os
import time
import random

def matrix_multiply(A, B, C, n):
    for i in range(n):
        for j in range(n):
            C[i][j] = sum(A[i][k] * B[k][j] for k in range(n))
    return C

def record_time(n_values, data_type):
    user_time_totals = [0] * len(n_values)
    system_time_totals = [0] * len(n_values)

    print(f"Measuring User and System time for matrix multiplication ({data_type}):\n")

    for i in range(len(n_values)):
        initial_times = os.times()
        if data_type == 'int':
            A = [[random.randint(1, 100) for _ in range(n_values[i])] for _ in range(n_values[i])]
            B = [[random.randint(1, 100) for _ in range(n_values[i])] for _ in range(n_values[i])]
        else:
            A = [[random.uniform(1.0, 100.0) for _ in range(n_values[i])] for _ in range(n_values[i])]
            B = [[random.uniform(1.0, 100.0) for _ in range(n_values[i])] for _ in range(n_values[i])]
        C = [[0] * n_values[i] for _ in range(n_values[i])]
        meat_time_start = time.process_time()
        C = matrix_multiply(A, B, C, n_values[i])
        meat_time_end = time.process_time()
        final_times = os.times()

        user_time_totals[i] += (final_times.user - initial_times.user)
        system_time_totals[i] += (final_times.system - initial_times.system)

        print(f"User time for {data_type} values of size {n_values[i]}: {user_time_totals[i]} seconds")
        print(f"System time for {data_type} values of size {n_values[i]}: {system_time_totals[i]} seconds")
        print("\n")

n_values = [64, 128, 256, 512, 1024]

record_time(n_values, 'int')
print("First set complete.\n")
record_time(n_values, 'double')
