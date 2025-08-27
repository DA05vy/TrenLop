#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const int MAX_N = 100;  // Giới hạn n
const int MAX_M = 100;  // Giới hạn m

int f[MAX_N+1][MAX_M+1] = {0};  // Khởi tạo mảng tĩnh

void solution(int n, int m) {
    // Khởi tạo cơ bản: Số cách để có tổng = 0 là 1 (chọn không phần tử)
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 0; // Không có cách để có tổng = 0 trừ khi chọn không phần tử
    }

    // Tính số cách phân tích n thành tổng của các số nhỏ hơn hoặc bằng m
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= i) {
                f[j][i] = f[j - i][i] + f[j][i - 1]; // Sử dụng số i
            } else {
                f[j][i] = f[j][i - 1]; // Không thể sử dụng số i
            }
        }
    }

    // In bảng DP (không bắt buộc)
    cout << "Bảng DP:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << f[j][i] << " ";
        }
        cout << endl;
    }

    cout << "Số cách phân tích " << n << " là: " << f[n][m] << endl;
}

void printCombinations(int n, int m, vector<int>& current, int start) {
    // Nếu tổng đã đạt tới n, in kết quả
    if (n == 0) {
        for (int i = 0; i < current.size(); i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    // Duyệt từ start đến m
    for (int i = start; i <= m; i++) {
        if (i <= n) {
            current.push_back(i);
            printCombinations(n - i, m, current, i);  // Phép quay lui, cho phép lặp lại i
            current.pop_back();  // Quay lại, thử số khác
        }
    }
}

int main() {
    srand(time(0));  // Khởi tạo bộ sinh số ngẫu nhiên

    int n = rand() % 51 + 5;  // n là một số ngẫu nhiên từ 5 đến 55
    int m = rand() % 51 + 5;  // m là một số ngẫu nhiên từ 5 đến 55

    cout << "n = " << n << ", m = " << m << endl;  // In giá trị n và m ngẫu nhiên

    solution(n, m); // Gọi hàm tính số cách

    cout << "Các cách phân tích " << n << " thành tổng của các số <= " << m << " là: " << endl;
    vector<int> current;
    printCombinations(n, m, current, 1);  // Bắt đầu từ số 1 để liệt kê các cách
    return 0;
}
