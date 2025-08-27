#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Hàm kiểm tra xem một chuỗi có phải là số "1000" hay không (với điều kiện nó là số riêng lẻ)
bool isValid1000(string& s, int start, int end) {
    // Nếu số "1000" là ở đầu chuỗi hoặc sau dấu cách
    if (start > 0 && isdigit(s[start - 1])) return false;  // Trước đó có chữ số
    if (end < s.length() && isdigit(s[end])) return false;  // Sau đó có chữ số

    return true;
}

// Hàm thay thế các số "1000" riêng lẻ thành "mot nghin"
string replace1000(string& s) {
    string result = s;
    size_t pos = 0;
    
    // Tìm kiếm "1000" trong chuỗi và thay thế
    while ((pos = result.find("1000", pos)) != string::npos) {
        // Kiểm tra nếu "1000" đứng riêng lẻ
        if (isValid1000(result, pos, pos + 4)) {
            result.replace(pos, 4, "mot nghin");
            pos += 8; // Dịch chuyển qua "mot nghin"
        } else {
            pos += 4; // Tiến tới vị trí tiếp theo
        }
    }

    return result;
}

int main() {
    string s = "toi co 1000, Nam có 21000, Dong co 1000 va 500";
    
    // Tìm các số 1000 riêng lẻ trong chuỗi và thay thế
    string result = replace1000(s);
    
    // Đếm số lần xuất hiện của "1000" riêng lẻ
    int count = 0;
    size_t pos = 0;
    while ((pos = s.find("1000", pos)) != string::npos) {
        if (isValid1000(s, pos, pos + 4)) {
            count++;
        }
        pos += 4;
    }

    // Hiển thị kết quả
    cout << "Số lần xuất hiện của '1000' là: " << count << endl;
    cout << "Chuỗi sau khi thay thế: " << result << endl;

    return 0;
}
