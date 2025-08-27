#include <iostream>
using namespace std;

void sinh_chuoi_nhi_phan(int n, string chuoi) {
    if (chuoi.length() == n) {
        cout << chuoi << endl;
    } else {
        sinh_chuoi_nhi_phan(n, chuoi + "0");
        sinh_chuoi_nhi_phan(n, chuoi + "1");
    }
}

int main() {
    sinh_chuoi_nhi_phan(3, "");
    return 0;
}
