#include <iostream>
using namespace std;

int sumD(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumD(n / 10);
}

int main() {
    int num = 9876;
    cout << "Tong cac chu so cua " << num << " la: " << sumD(num) << endl;
    return 0;
}
