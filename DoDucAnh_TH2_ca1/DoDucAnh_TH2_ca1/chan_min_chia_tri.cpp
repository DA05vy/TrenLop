#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>  // Để sử dụng INT_MAX
using namespace std;

// Hàm đệ quy tìm số chẵn nhỏ nhất trong mảng
int findSmallestEven(const vector<int>& arr, int l, int r) {
    // Trường hợp cơ bản: Nếu chỉ còn một phần tử
    if (l == r) {
        if (arr[l] % 2 == 0) {  // Nếu phần tử là số chẵn
            return arr[l];
        } else {
            return INT_MAX;  // Trả về INT_MAX nếu không phải số chẵn
        }
    }

    // Tính chỉ số giữa
    int m = (l + r) / 2;

    // Gọi đệ quy để tìm số chẵn nhỏ nhất trong hai nửa
    int leftMin = findSmallestEven(arr, l, m);
    int rightMin = findSmallestEven(arr, m + 1, r);

    // Trả về số chẵn nhỏ nhất trong cả hai nửa
    return min(leftMin, rightMin);
}

int main() {
    // Khởi tạo seed cho hàm sinh số ngẫu nhiên
    srand(time(0));

    // Sinh số lượng phần tử ngẫu nhiên trong khoảng từ 20 đến 50
    int n = rand() % 31 + 20;  // Số lượng phần tử trong danh sách, từ 20 đến 50

    // Khởi tạo danh sách ngẫu nhiên với n phần tử
    vector<int> arr(n);

    // Sinh giá trị ngẫu nhiên cho từng phần tử trong danh sách, giá trị có thể là số nguyên bất kỳ
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 201 - 100;  // Sinh giá trị trong khoảng [-100, 100]
    }

    // In ra danh sách
    cout << "Danh sach ban dau (so luong: " << n << "): ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Gọi hàm findSmallestEven để tìm số chẵn nhỏ nhất
    int result = findSmallestEven(arr, 0, arr.size() - 1);

    // Kiểm tra kết quả
    if (result == INT_MAX) {
        cout << "Khong tim thay so chan trong danh sach." << endl;
    } else {
        cout << "So chan nho nhat trong danh sach la: " << result << endl;
    }

    return 0;
}

