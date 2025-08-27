#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hàm đệ quy tính tổng các số dương trong mảng
double sumPositiveNumbers(const vector<double>& arr, int l, int r) {
    // Trường hợp cơ bản: Nếu chỉ còn một phần tử
    if (l == r) {
        return (arr[l] > 0) ? arr[l] : 0;  // Nếu số dương thì trả về giá trị, nếu không trả về 0
    }

    // Tính chỉ số giữa
    int m = (l + r) / 2;

    // Gọi đệ quy để tính tổng cho hai nửa
    double leftSum = sumPositiveNumbers(arr, l, m);
    double rightSum = sumPositiveNumbers(arr, m + 1, r);

    // Trả về tổng các số dương trong cả hai nửa
    return leftSum + rightSum;
}

int main() {
    // Khởi tạo seed cho hàm sinh số ngẫu nhiên
    srand(time(0));

    // Sinh số lượng phần tử ngẫu nhiên trong khoảng từ 20 đến 50
    int n = rand() % 31 + 20;  // Số lượng phần tử trong danh sách, từ 20 đến 50

    // Khởi tạo danh sách ngẫu nhiên với n phần tử
    vector<double> arr(n);

    // Sinh giá trị ngẫu nhiên cho từng phần tử trong danh sách, giá trị có thể là âm hoặc dương
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 2001 - 1000) / 10.0;  // Sinh giá trị trong khoảng [-100.0, 100.0]
    }

    // In ra danh sách
    cout << "Danh sach ban dau (so luong: " << n << "): ";
    for (double num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Gọi hàm sumPositiveNumbers để tính tổng các số dương
    double result = sumPositiveNumbers(arr, 0, arr.size() - 1);

    // In kết quả
    cout << "Tong cac so duong trong danh sach la: " << result << endl;

    return 0;
}

