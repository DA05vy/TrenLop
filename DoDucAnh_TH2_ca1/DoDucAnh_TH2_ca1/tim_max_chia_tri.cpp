#include <iostream>
using namespace std;

// Hàm đệ quy để tìm giá trị lớn nhất trong mảng
int findMax(int *a, int l, int r) {
    // Trường hợp dừng: nếu chỉ còn một phần tử, trả về phần tử đó
    if (l == r) {
        return a[l];
    }

    // Tính chỉ số giữa
    int m = (l + r) / 2;

    // Gọi đệ quy để tìm giá trị lớn nhất trong hai nửa
    int leftMax = findMax(a, l, m);
    int rightMax = findMax(a, m + 1, r);

    // Trả về giá trị lớn nhất giữa hai nửa
    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    // Khởi tạo danh sách 15 giá trị ngẫu nhiên
    int a[15] = {42, 15, 23, 8, 4, 16, 35, 50, 29, 10, 1, 37, 27, 33, 18};

    cout << "Danh sach ban dau: ";
    for (int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Gọi hàm findMax để tìm giá trị lớn nhất trong mảng
    int maxVal = findMax(a, 0, 14);

    // In ra giá trị lớn nhất
    cout << "Gia tri lon nhat trong mang: " << maxVal << endl;

    return 0;
}

