#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Hàm cộng hai số lớn
string addLargeNumbers(string &m, string &n) {
    int lenM = m.size();
    int lenN = n.size();
    int carry = 0;  // Biến carry để lưu phần mang theo
    string result = "";

    // Đảo ngược chuỗi để cộng từ vị trí cuối cùng
    int i = lenM - 1;
    int j = lenN - 1;

    // Cộng các chữ số tương ứng từ phải sang trái
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0) sum += m[i] - '0';  // Chuyển ký tự thành số và cộng
        if (j >= 0) sum += n[j] - '0';  // Chuyển ký tự thành số và cộng

        carry = sum / 10;  // Lấy phần mang theo
        result += (sum % 10) + '0';  // Lấy chữ số đơn vị và thêm vào kết quả

        i--;
        j--;
    }

    // Đảo ngược lại kết quả vì chúng ta đã cộng từ cuối lên đầu
    reverse(result.begin(), result.end());

    return result;
}

// Hàm tạo số ngẫu nhiên có đúng độ dài maxLen (200 chữ số)
string generateRandomNumber(int maxLen) {
    string result = "";
    // Đảm bảo số không bắt đầu bằng số 0
    result += rand() % 9 + '1';  // Chọn chữ số đầu tiên từ 1 đến 9

    // Tạo các chữ số tiếp theo từ 0 đến 9
    for (int i = 1; i < maxLen; i++) {
        result += rand() % 10 + '0';  // Các chữ số tiếp theo từ 0 đến 9
    }
    return result;
}

int main() {
    srand(time(0));  // Khởi tạo seed cho hàm random

    int maxLen = rand() % 101 - 10;

    string m = generateRandomNumber(maxLen);  // Số m ngẫu nhiên có 200 chữ số
    string n = generateRandomNumber(maxLen);  // Số n ngẫu nhiên có 200 chữ số

    // Hiển thị các số ngẫu nhiên
    cout << "Số m ngẫu nhiên: " << m << endl;
    cout << "Số n ngẫu nhiên: " << n << endl;

    // Tính tổng của m và n
    string sum = addLargeNumbers(m, n);

    // Hiển thị kết quả
    cout << "Tổng của m và n là: " << sum << endl;

    return 0;
}
