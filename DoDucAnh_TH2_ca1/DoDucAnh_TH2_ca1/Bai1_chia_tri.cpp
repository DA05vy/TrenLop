#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Cấu trúc học sinh
struct Student {
    string firstName;
    string lastName;
    int birthYear;
    string address;

    // Hàm trả về tên đầy đủ của học sinh
    string fullName() const {
        return firstName + " " + lastName;
    }
};

// Hàm sắp xếp danh sách học sinh theo tên (theo thứ tự từ điển)
void merge(vector<Student>& students, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Student> left(n1), right(n2);

    for (int i = 0; i < n1; i++) left[i] = students[l + i];
    for (int j = 0; j < n2; j++) right[j] = students[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i].fullName() < right[j].fullName()) {
            students[k++] = left[i++];
        } else {
            students[k++] = right[j++];
        }
    }

    while (i < n1) students[k++] = left[i++];
    while (j < n2) students[k++] = right[j++];
}

void mergeSort(vector<Student>& students, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(students, l, m);
        mergeSort(students, m + 1, r);
        merge(students, l, m, r);
    }
}

// Hàm tìm kiếm nhị phân trong danh sách học sinh
int binarySearch(const vector<Student>& students, const string& name, int l, int r) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (students[m].fullName() == name) {
            return m; // Trả về vị trí nếu tìm thấy
        } else if (students[m].fullName() < name) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1; // Không tìm thấy
}

int main() {
    // Khởi tạo danh sách học sinh
    vector<Student> students = {
        {"Nguyen", "A", 2000, "Hanoi"},
        {"Tran", "B", 1998, "Ho Chi Minh City"},
        {"Pham", "C", 2001, "Danang"},
        {"Le", "D", 1997, "Hanoi"},
        {"Nguyen", "E", 2002, "Ho Chi Minh City"},
        {"Pham", "F", 1999, "Danang"}
    };

    // Sắp xếp danh sách học sinh theo tên
    mergeSort(students, 0, students.size() - 1);

    // In danh sách học sinh đã sắp xếp
    cout << "Danh sach hoc sinh sau khi sap xep theo ten:" << endl;
    for (const auto& student : students) {
        cout << student.fullName() << ", Sinh: " << student.birthYear << ", Dia chi: " << student.address << endl;
    }

    // Nhập tên học sinh cần tìm
    string name;
    cout << "\nNhap ten hoc sinh can tim (vd: 'Nguyen A'): ";
    getline(cin, name);

    // Tìm kiếm học sinh trong danh sách
    int position = binarySearch(students, name, 0, students.size() - 1);

    // Hiển thị kết quả tìm kiếm
    if (position != -1) {
        cout << "\nThong tin hoc sinh " << name << ":\n";
        cout << "Ten: " << students[position].fullName() << ", Sinh: " << students[position].birthYear
             << ", Dia chi: " << students[position].address << endl;
    } else {
        cout << "\nKhong tim thay hoc sinh " << name << " trong danh sach." << endl;
    }

    return 0;
}
