#include<iostream>
using namespace std;

int fibo( int n ){
    if ( n <= 2 ) return 1;
    else return fibo(n-1) + fibo(n-2);
}

long long fibo_khu(int n ){
    long t1 = 1, t2 = 1, tn;
    for ( int i = 3; i <= n; i++ ){
        tn = t1 + t2;
        t2 = t1;
        t1 = tn;
    }
    return tn;
}

int main(){
    int n; cin >> n;
    cout << "Tim fibo bang de quy: " << fibo(n) << endl;
    cout << "Tim fibo bang khu de quy: " << fibo_khu(n) << endl;
    return 0;
}
