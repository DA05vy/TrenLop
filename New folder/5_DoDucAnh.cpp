#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b) {
    int tg = a;
    a = b;
    b = tg;
}

// Hàm hiển thị một cấu hình hoán vị
// x[]: mảng chứa cấu hình hoán vị hiện tại
// n: độ dài của hoán vị
void view_config_permutation(int x[], int n) {
    cout << "{ ";
    for (int i = 1; i <= n; ++i) { // Duyệt từ chỉ số 1 đến n
        cout << x[i] << (i == n ? "" : ", ");
    }
    cout << " }" << endl;
}

// Hàm sinh cấu hình hoán vị tiếp theo từ cấu hình đang có
// x[]: mảng chứa cấu hình hoán vị hiện tại
// n: độ dài của hoán vị
// i: chỉ mục của phần tử liền trước đoạn cuối giảm dần
void next_config_permutation(int x[], int n, int i) {
    // Bước 1: Tìm x[k] bé nhất trong đoạn cuối lớn hơn x[i]
    int k = n;
    while (x[k] < x[i]) {
        k--;
    }
    // Bước 2: Đổi giá trị x[i] và x[k]
    swap(x[i], x[k]);
    // Bước 3: Đảo ngược đoạn cuối (từ i+1 đến n)
    int j = n;
    i++; // Bắt đầu từ vị trí sau i
    while (i < j) {
        swap(x[i], x[j]);
        i++;
        j--;
    }
}

// Hàm liệt kê tất cả các cấu hình hoán vị của tập {1, 2, ..., n}
// n_val: kích thước của tập và độ dài của hoán vị
void listing_configs_permutations(int n_val) {
    // Khởi tạo cấu hình đầu tiên {1 2 … n}
    // Sử dụng mảng C-style với kích thước n_val+1 để phù hợp với chỉ số 1..n_val
    int* x = new int[n_val + 1];
    for (int i = 1; i <= n_val; ++i) {
        x[i] = i;
    }

    int i;
    do {
        view_config_permutation(x, n_val); // In một cấu hình

        // Tìm phần tử liền trước đoạn cuối giảm dần
        i = n_val - 1;
        while (i > 0 && x[i] > x[i + 1]) {
            i--;
        }

        if (i > 0) { // Nếu chưa phải cấu hình cuối cùng (đoạn cuối không giảm dần toàn bộ)
            next_config_permutation(x, n_val, i); // Sinh cấu hình kế tiếp
        }
    } while (i > 0); // Lặp cho đến khi i <= 0 (tức là đã duyệt qua cấu hình cuối)

    delete[] x; // Giải phóng bộ nhớ
}

int main() {
    int n = 3;
    cout << "Cac hoan vi cua S = {1, ..., " << n << "}:" << endl;
    listing_configs_permutations(n);
    return 0;
}
