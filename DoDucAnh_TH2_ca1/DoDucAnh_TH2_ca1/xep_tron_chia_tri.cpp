#include <iostream>
using namespace std;

void merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1;  // Kích thước nửa trái
    int n2 = r - m;      // Kích thước nửa phải

    int left[n1], right[n2];

    // Sao chép nửa đầu của a vào left
    for (int i = 0; i < n1; i++) {
        left[i] = a[l + i];
    }

    // Sao chép nửa còn lại của a vào right
    for (int j = 0; j < n2; j++) {
        right[j] = a[m + 1 + j];
    }

    // Trộn hai nửa mảng vào mảng a
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            a[k] = left[i];
            i++;
        } else {
            a[k] = right[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại của left nếu có
    while (i < n1) {
        a[k] = left[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại của right nếu có
    while (j < n2) {
        a[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int *a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;  // Tính chỉ số giữa mảng
        merge_sort(a, l, m);   // Sắp xếp nửa trái
        merge_sort(a, m + 1, r);  // Sắp xếp nửa phải
        merge(a, l, m, r);     // Trộn hai nửa đã sắp xếp lại với nhau
    }
}

int main() {
    // Khởi tạo danh sách 15 giá trị ngẫu nhiên
    int a[15] = {42, 15, 23, 8, 4, 16, 35, 50, 29, 10, 1, 37, 27, 33, 18};

    cout << "Danh sach ban dau: ";
    for (int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // Gọi hàm merge_sort để sắp xếp
    merge_sort(a, 0, 14);

    // In ra danh sách sau khi sắp xếp
    cout << "Danh sach sau khi sap xep: ";
    for (int i = 0; i < 15; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

