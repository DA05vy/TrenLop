#include <iostream>
#include <vector>

using namespace std;

vector<long long> memo;

long long fibo(int n) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibo(n - 1) + fibo(n - 2);
    return memo[n];
}

int main() {
    int n_fib = 10;
    memo.assign(n_fib + 1, -1);  //Khoi tao voi tat ca gia tri -1
    cout << "So Fibonacci thu " << n_fib << " la: " << fibo(n_fib) << endl;
    return 0;
}
