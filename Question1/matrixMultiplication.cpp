#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
long long fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}
double fibrecursion(){
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i=0;i<50;i++){
        fibonacci_recursive(i);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double timeTaken=  end.tv_sec+(end.tv_nsec/1e9)-(start.tv_sec+(start.tv_nsec/1e9));
    return timeTaken;
}
// --------------------------------------------------------------------------------------------------

long long fibonacci_loop(int n) {
    if (n <= 1)
        return n;
    long long prev = 0, curr = 1, next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}
double fibLoop(){
    struct timespec start,end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    for(int i=0;i<50;i++){
        fibonacci_loop(i);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double timeTaken=  end.tv_sec+(end.tv_nsec/1e9)-(start.tv_sec+(start.tv_nsec/1e9));
    return timeTaken;
}
// --------------------------------------------------------------------------------------------------

long long fibonacci_memoization(int n ,long long* dp) {
    if (dp[n] != -1)
        return dp[n];
    if (n <= 1)
        return dp[n] = n;
    return dp[n] = fibonacci_memoization(n - 1, dp) + fibonacci_memoization(n - 2, dp);
}
double fib_memoization(){
    struct timespec start,end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    long long dp[51]={-1};        
    fibonacci_memoization(50,dp);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double timeTaken=  end.tv_sec+(end.tv_nsec/1e9)-(start.tv_sec+(start.tv_nsec/1e9));
    return timeTaken;
}
//--------------------------------------------------------------------------------------------------

long long fibonacci_loop_memoization(int n, long long* dp) {
    if (dp[n] != -1)
        return dp[n];
    if (n <= 1)
        return dp[n] = n;
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

double fib_loop_memoization(){
    struct timespec start,end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    long long dp[51]={-1};
    fibonacci_loop_memoization(50,dp);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
    double timeTaken=  end.tv_sec+(end.tv_nsec/1e9)-(start.tv_sec+(start.tv_nsec/1e9));
    return timeTaken;
}
// --------------------------------------------------------------------------------------------------

int main() {
    // k represent the number of trails that we want to do.
    int k=3;        
    vector<string> methods={"Recursion", "Loop", "Recursion with memoization", "Loop with memoization"};
    vector<vector<double>> timeMatrix(4,vector<double>(k,0));
    vector<double> avgTime(4,0);
    for(int j=0;j<4;j++){
        for(int i=0;i<k;i++){
            timeMatrix[j][i]=j==0?fibrecursion():j==1?fibLoop():j==2?fib_memoization():fib_loop_memoization();
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<k;j++){
            avgTime[i]+=timeMatrix[i][j];
        }
        avgTime[i]/=k;
    }

    // Print the k values of the time taken for each method
    cout<<"Time taken for fibonacci series of 50 numbers using different methods"<<endl;
    for(int i=0;i<4;i++){
        cout<<methods[i]<<" : ";
        for(int j=0;j<k;j++){
            cout<<timeMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Average time taken for fibonacci series of 50 numbers using different methods"<<endl;
    
    for(int i=0;i<4;i++){
        cout<<methods[i]<<" : "<<avgTime[i]<<endl;
    }
// --------------------------------------------------------------------------------------------------
    // store the timeMatrix data in a file
    FILE *fp;
    fp = fopen("output.txt", "w");
    for(int i=0;i<4;i++){
        for(int j=0;j<k;j++){
            fprintf(fp,"%lf ",timeMatrix[i][j]);
        }
        fprintf(fp,"\n");
    }
    for(int i=0;i<4;i++){
        fprintf(fp,"%lf\n",avgTime[i]);
    }
// --------------------------------------------------------------------------------------------------

    return 0;
}
