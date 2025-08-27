#include <iostream>
#include <vector>
using namespace std;

// Hàm hiển thị một cấu hình tập con
// x[]: mảng chứa các phần tử của tập con hiện tại
// k: số lượng phần tử trong tập con
void view_config_subset(int x[], int k) {
    cout << "{ ";
    for (int i = 1; i <= k; ++i) { // Duyệt từ chỉ số 1 đến k
        cout << x[i] << (i == k ? "" : ", ");
    }
    cout << " }" << endl;
}

// Hàm sinh cấu hình tập con tiếp theo từ cấu hình đang có
// x[]: mảng chứa các phần tử của tập con hiện tại
// k: số lượng phần tử trong tập con
// i: chỉ mục của phần tử đầu tiên chưa đạt giới hạn trên
void next_config_subset(int x[], int k, int i) {
    x[i] += 1; // Tăng giá trị của phần tử x[i] lên 1
    i++;       // Chuyển sang phần tử kế tiếp
    while (i <= k) { // Đặt các phần tử x[i+1], ..., x[k] bằng cận dưới
        x[i] = x[i - 1] + 1; // Phần tử sau bằng phần tử trước cộng 1
        i++;
    }
}

// Hàm liệt kê tất cả các cấu hình tập con k phần tử từ {1, 2, ..., n}
// k_val: số lượng phần tử trong mỗi tập con
// n_val: tổng số phần tử trong tập gốc {1, 2, ..., n}
void listing_configs_subsets(int k_val, int n_val) {
    // Khởi tạo cấu hình đầu tiên {1 2 … k}
    // Sử dụng mảng C-style với kích thước k_val+1 để phù hợp với chỉ số 1..k_val
    int* x = new int[k_val + 1];
    for (int i = 1; i <= k_val; ++i) {
        x[i] = i;
    }

    int i;
    do {
        view_config_subset(x, k_val); // In một cấu hình

        // Tìm phần tử đầu tiên chưa đạt giới hạn trên (n - k + i)
        i = k_val;
        while (i > 0 && x[i] == n_val - k_val + i) {
            i--;
        }

        if (i > 0) { // Nếu chưa phải cấu hình cuối cùng
            next_config_subset(x, k_val, i); // Sinh cấu hình kế tiếp
        }
    } while (i > 0); // Lặp cho đến khi i <= 0 (tức là đã duyệt qua cấu hình cuối)

    delete[] x; // Giải phóng bộ nhớ
}

int main() {
    int n = 4;
    int k = 2;
    cout << "Cac tap con " << k << " phan tu cua S = {1, ..., " << n << "}:" << endl;
    listing_configs_subsets(k, n);
    return 0;
}
