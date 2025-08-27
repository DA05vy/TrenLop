#include <bits/stdc++.h>
using namespace std;

// Hàm giải bài toán Balo 0-1 bằng Quy hoạch động
void qhd(vector<int> w, vector<int> v, int n, int wm) {
    // f[i][j] là giá trị tối đa khi chọn từ 1 đến i vật, với tổng khối lượng tối đa là j
    int f[n + 1][wm + 1] = {0};

    // Khởi tạo hàng đầu tiên (không chọn vật nào)
    for (int j = 0; j <= wm; j++) {
        f[0][j] = 0;
    }

    // Tính bảng quy hoạch động
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= wm; j++) {
            if (w[i - 1] > j) {
                // Không thể chọn vật i vì quá nặng
                f[i][j] = f[i - 1][j];
            } else {
                // Có thể chọn hoặc không chọn vật i
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i - 1]] + v[i - 1]);
            }
        }
    }
    
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= wm; j++) {
    //         cout << f[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

    // In ra giá trị lớn nhất đạt được
    cout << "Gia tri toi uu (QHD): " << f[n][wm] << endl;

    // Truy vết để tìm các vật đã chọn
    cout << "Cac vat da chon (QHD): ";
    int wLeft = wm;
    for (int i = n; i > 0; i--) {
        // Nếu giá trị thay đổi so với hàng trên, vật i đã được chọn
        if (f[i][wLeft] != f[i - 1][wLeft]) {
            cout << i << " "; // In chỉ số vật đã chọn
            wLeft -= w[i - 1]; // Trừ khối lượng của vật đó
        }
    }
    cout << endl;
}

// Hàm giải bài toán balo bằng thuật toán Tham lam
void thamlam(vector<int> w, vector<int> v, int n, int wm) {
    // Tạo mảng tỷ lệ giá trị/khối lượng cùng chỉ số
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++) {
        ratio[i].first = (double)v[i] / w[i];  // Tính giá trị trên mỗi đơn vị khối lượng
        ratio[i].second = i;  // Lưu chỉ số vật
    }

    // Sắp xếp theo tỷ lệ giảm dần
    sort(ratio.begin(), ratio.end(), greater<pair<double, int>>());

    int sums = 0;
    int i = 0;
    vector<int> select;

    // Chọn các vật theo thứ tự tỷ lệ cao đến thấp
    while (i < n && sums + w[ratio[i].second] <= wm) {
        sums += w[ratio[i].second];
        select.push_back(ratio[i].second + 1);  // Lưu chỉ số vật (1-based)
        i++;
    }

    // In kết quả
    if (sums == wm) {
        cout << "Tham lam chon du khoi luong." << endl;
    } else {
        cout << "Tham lam chon con thieu " << wm - sums << " khoi luong." << endl;
    }

    cout << "Cac vat da chon (Tham lam): ";
    for (auto i : select) cout << i << " ";
    cout << endl;
}

int main() {
    srand(time(0)); // Khởi tạo seed random

    // Sinh ngẫu nhiên số lượng vật từ 8 đến 38
    int n = rand() % 31 + 8;
    cout << "So luong vat: " << n << endl;

    vector<int> w(n), v(n); // w: khối lượng, v: giá trị

    // Khởi tạo ngẫu nhiên giá trị và khối lượng từng vật
    for (int i = 0; i < n; i++) {
        w[i] = rand() % 11 + 1; // Khối lượng từ 1 đến 11
        v[i] = rand() % 11 + 1; // Giá trị từ 1 đến 11
    }

    // In danh sách các vật
    cout << "Danh sach cac vat (w - v):" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(2) << i + 1 << "   " << setw(2) << w[i] << " - " << setw(2) << v[i] << endl;
    }

    // Sinh ngẫu nhiên khối lượng tối đa của balo từ 10 đến 60
    int wm = rand() % 51 + 10;
    cout << "Khoi luong toi da cua balo: " << wm << endl;

    // Gọi hàm giải bằng Quy hoạch động
    qhd(w, v, n, wm);

    // Gọi hàm giải bằng Tham lam
    thamlam(w, v, n, wm);

    return 0;
}
