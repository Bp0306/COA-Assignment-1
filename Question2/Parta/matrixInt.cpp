#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template<typename T>
void matrixMultiply(const vector<vector<T>>& A, const vector<vector<T>>& B, vector<vector<T>>& C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

template<typename T>
void runMatrixMultiplication(int N) {
    vector<vector<T>> A(N, vector<T>(N, 1));
    vector<vector<T>> B(N, vector<T>(N, 1));
    vector<vector<T>> C(N, vector<T>(N, 0));
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    matrixMultiply(A, B, C, N);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    cout << "Time taken for matrix multiplication: " << elapsed.count() << " seconds" << endl;
}

int main() {
    vector<int> sizes = {64, 128, 256, 512, 1024};

    cout << "Matrix Multiplication with Integer Data Type:" << endl;
    for (int N : sizes) {
        cout << "Size: " << N << "x" << N << endl;
        runMatrixMultiplication<int>(N);
    }

    cout << "\nMatrix Multiplication with Double Data Type:" << endl;
    for (int N : sizes) {
        cout << "Size: " << N << "x" << N << endl;
        runMatrixMultiplication<double>(N);
    }

    return 0;
}
