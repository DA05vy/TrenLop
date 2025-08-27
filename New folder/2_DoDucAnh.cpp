#include <iostream>
using namespace std;

void sinh_chuoi_ab(int n, string chuoi) {
    if (chuoi.length() == n) {
        cout << chuoi << endl;
    } else {
        sinh_chuoi_ab(n, chuoi + "a");
        sinh_chuoi_ab(n, chuoi + "b");
    }
}

int main() {
    sinh_chuoi_ab(3, " ");
    return 0;
}

