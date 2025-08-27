#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Hàm tính mảng Z cho chuỗi
vector<int> calculateZ(string& str) {
    int n = str.length();
    vector<int> Z(n, 0);
    int l = 0, r = 0;
    
    for (int i = 1; i < n; ++i) {
        if (i <= r) {
            Z[i] = min(r - i + 1, Z[i - l]);
        }
        while (i + Z[i] < n && str[Z[i]] == str[i + Z[i]]) {
            ++Z[i];
        }
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    return Z;
}

// Hàm tìm từ đầu tiên trong đoạn văn bản
string getFirstWord(string& text) {
    stringstream ss(text);
    string firstWord;
    ss >> firstWord; // Lấy từ đầu tiên
    return firstWord;
}

int main() {
    // Đoạn văn bản ví dụ
    string text = "toi co 1000, Nam có 1000, toi co 1000";
    
    // Lấy từ đầu tiên
    string firstWord = getFirstWord(text);
    
    // Tạo chuỗi ghép từ từ đầu tiên và đoạn văn bản
    string combined = firstWord + "$" + text;
    
    // Tính mảng Z cho chuỗi đã ghép
    vector<int> Z = calculateZ(combined);
    
    // Đếm số lần xuất hiện của từ đầu tiên trong đoạn văn bản
    int count = 0;
    for (int i = firstWord.length() + 1; i < Z.size(); ++i) {
        if (Z[i] == firstWord.length()) {
            ++count;
        }
    }
    
    // In ra kết quả
    cout << "Từ đầu tiên: " << firstWord << endl;
    cout << "Số lần xuất hiện: " << count << endl;

    return 0;
}
