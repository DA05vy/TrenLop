#include <iostream>
#include <vector>
#include <climits>
#include <ctime>
#include <algorithm>
using namespace std;

void coin_changing(int m, vector<int>& c, vector<int>& f, vector<int>& s) {
    int n = c.size();
    f[0] = 0;  // Không cần tiền tệ nào để trả 0

    // Duyệt qua các số tiền từ 1 đến m
    for (int i = 1; i <= m; i++) {
        int min_val = INT_MAX;  // Khởi tạo giá trị tối thiểu
        for (int j = 0; j < n; j++) {
            if (c[j] <= i && f[i - c[j]] != INT_MAX && f[i - c[j]] + 1 < min_val) {
                min_val = f[i - c[j]] + 1;  // Cập nhật số tờ ít nhất
                s[i] = j;  // Lưu lại loại tiền sử dụng
            }
        }
        f[i] = min_val;  // Cập nhật số tờ tiền ít nhất cho số tiền i
    }
}

void print_result(int m, vector<int>& c, vector<int>& f, vector<int>& s) {
    // Kiểm tra xem có thể tạo được số tiền m không
    if (f[m] == INT_MAX) {
        cout << "Không thể đổi số tiền " << m << " với các mệnh giá đã cho." << endl;
        return;
    }

    // In kết quả số tờ tiền cần dùng
    cout << "Tổng số tờ tiền cần dùng: " << f[m] << endl;

    cout << "Các loại mệnh giá cần dùng: ";
    int i = m;
    while (i > 0) {
        int coin_type = s[i];
        cout << c[coin_type] << " ";  // In ra loại tiền
        i -= c[coin_type];  // Giảm đi số tiền đã sử dụng
    }
    cout << endl;
}

int main() {
    int n, m;
    srand(time(0));
    
    // Nhập số lượng mệnh giá và số tiền cần trả
    cout << "Nhập số lượng mệnh giá: "; 
    n = rand() % 10 + 1;  // Số lượng mệnh giá từ 1 đến 10
    cout << n << endl;
    
    vector<int> c(n);  // Mảng các mệnh giá
    cout << "Nhập các mệnh giá: ";
    for (int i = 0; i < n; i++) {
        c[i] = rand() % 100 + 1;  // Mệnh giá từ 1 đến 100
        cout << c[i] << " "; 
    }
    
    //sort(c.rbegin(), c.rend());
    
    cout << endl;
    cout << "Nhập số tiền cần trả: ";
    m = rand() % 900 + 100;  // Số tiền cần trả từ 100 đến 999
    cout << m << endl;

    // Mảng f lưu trữ số tờ tiền ít nhất để tạo ra số tiền i
    // Mảng s lưu trữ loại tiền cuối cùng sử dụng để tạo ra số tiền i
    vector<int> f(m + 1, INT_MAX);
    vector<int> s(m + 1, -1);

    // Gọi hàm quy hoạch động
    coin_changing(m, c, f, s);

    // In kết quả
    print_result(m, c, f, s);

    return 0;
}
