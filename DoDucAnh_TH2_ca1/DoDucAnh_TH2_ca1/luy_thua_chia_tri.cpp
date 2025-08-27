#include <iostream>
using namespace std;
double power(double a, int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    // Nếu n là số chẵn
    if (n % 2 == 0) {
        double half = power(a, n / 2);  // Tính a^(n/2)
        return half * half;  // a^n = (a^(n/2))^2
    }
    // Nếu n là số lẻ
    else {
        return a * power(a, n - 1);  // a^n = a * a^(n-1)
    }
}

int main() {
    double a;
    int n;
    cin >> a >> n;
    double result = power(a, n);
    cout << a << " ^ " << n << " = " << result << endl;

    return 0;
}

