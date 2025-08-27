#include <iostream>
#include <vector>
#include <string>

// Sử dụng namespace std để không cần gõ "std::"
using namespace std;

// Danh sách sinh viên có sẵn (đây là "giá trị" mà hoán vị sẽ ánh xạ tới)
vector<string> students_to_arrange = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

// Hàm hoán đổi giá trị hai phần tử (dùng cho các chỉ số)
void swap_idx(int &a, int &b) {
    int tg = a;
    a = b;
    b = tg;
}

// Hàm hiển thị một cách xếp sinh viên (hoán vị)
// x[]: mảng chứa cấu hình hoán vị của các CHỈ SỐ sinh viên
// n: tổng số sinh viên và ghế
void view_config_student_arrangement(int x[], int n) {
    cout << "{ ";
    for (int i = 1; i <= n; ++i) { // Duyệt từ chỉ số 1 đến n
        // x[i] là chỉ số 1-based của sinh viên trong mảng students_to_arrange
        // Cần trừ 1 để ra chỉ số mảng 0-based
        cout << students_to_arrange[x[i] - 1] << " (ghe " << i << ")" << (i == n ? "" : ", ");
    }
    cout << " }" << endl;
}

// Hàm sinh cấu hình hoán vị chỉ số sinh viên tiếp theo
// x[]: mảng chứa cấu hình hoán vị hiện tại của các chỉ số
// n: độ dài của hoán vị
// i: chỉ mục của phần tử liền trước đoạn cuối giảm dần
void next_config_student_arrangement(int x[], int n, int i) {
    // Bước 1: Tìm x[k] bé nhất trong đoạn cuối lớn hơn x[i]
    int k = n;
    while (x[k] < x[i]) {
        k--;
    }
    // Bước 2: Đổi giá trị x[i] và x[k]
    swap_idx(x[i], x[k]);
    // Bước 3: Đảo ngược đoạn cuối (từ i+1 đến n)
    int j = n;
    i++;
    while (i < j) {
        swap_idx(x[i], x[j]);
        i++;
        j--;
    }
}

// Hàm liệt kê tất cả các cách xếp sinh viên (hoán vị)
// n_val: tổng số sinh viên và ghế
void listing_student_arrangements(int n_val) {
    // x[] sẽ lưu các số từ 1 đến n_val, đại diện cho vị trí của sinh viên trong students_to_arrange
    int* x = new int[n_val + 1];
    for (int i = 1; i <= n_val; ++i) {
        x[i] = i; // Cấu hình đầu tiên: (Trang, Cong, Trung, ...)
    }

    int i;
    do {
        view_config_student_arrangement(x, n_val); // In một cấu hình xếp

        i = n_val - 1;
        while (i > 0 && x[i] > x[i + 1]) {
            i--;
        }

        if (i > 0) {
            next_config_student_arrangement(x, n_val, i);
        }
    } while (i > 0);

    delete[] x;
}

int main() {
    int num_students_and_chairs = students_to_arrange.size(); // Có 6 sinh viên và 6 ghế

    cout << "Cac cach xep " << num_students_and_chairs << " sinh vien vao "
         << num_students_and_chairs << " ghe (thu tu 1 -> 6):" << endl;
    listing_student_arrangements(num_students_and_chairs);
    return 0;
}
