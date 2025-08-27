#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> students_list = {"Trang", "Cong", "Trung", "Binh", "Hoan", "Mai"};

// Hàm hiển thị một cách lấy sinh viên (tập con)
// x[]: mảng chứa các chỉ mục của sinh viên được chọn
// k: số lượng sinh viên được chọn
void view_config_students(int x[], int k) {
    cout << "{ ";
    for (int i = 1; i <= k; ++i) { // Duyệt từ chỉ số 1 đến k
        // x[i] là chỉ số trong tập {1, ..., n}, cần trừ 1 để ra chỉ số mảng 0-based
        cout << students_list[x[i] - 1] << (i == k ? "" : ", ");
    }
    cout << " }" << endl;
}

// Hàm sinh cấu hình tiếp theo cho việc chọn sinh viên (tập con)
// x[]: mảng chứa các chỉ mục của sinh viên được chọn
// k: số lượng sinh viên được chọn
// i: chỉ mục của phần tử đầu tiên chưa đạt giới hạn trên
void next_config_students(int x[], int k, int i) {
    x[i] += 1;
    i++;
    while (i <= k) {
        x[i] = x[i - 1] + 1;
        i++;
    }
}

// Hàm liệt kê các cách lấy k sinh viên từ n sinh viên
// k_val: số lượng sinh viên muốn lấy
// n_val: tổng số sinh viên có sẵn
void listing_student_combinations(int k_val, int n_val) {
    int* x = new int[k_val + 1];
    for (int i = 1; i <= k_val; ++i) {
        x[i] = i;
    }

    int i;
    do {
        view_config_students(x, k_val); // In một cấu hình sinh viên

        i = k_val;
        while (i > 0 && x[i] == n_val - k_val + i) {
            i--;
        }

        if (i > 0) {
            next_config_students(x, k_val, i);
        }
    } while (i > 0);

    delete[] x;
}

int main() {
    int k_students = 4;
    int n_students = students_list.size();

    cout << "Cac cach lay " << k_students << " sinh vien tu:";
    for (const auto& s : students_list) {
        cout << " " << s;
    }
    cout << ":" << endl;
    listing_student_combinations(k_students, n_students);
    return 0;
}
