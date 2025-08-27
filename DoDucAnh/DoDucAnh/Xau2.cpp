#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Hàm đếm số lần xuất hiện của từ "child" trong văn bản
int demSoLanXuatHienChild(const vector<string>& words) {
    int count = 0;
    for (const string& word : words) {
        if (word == "child") {
            count++;
        }
    }
    return count;
}

// Hàm thay thế tất cả các từ "child" thành "children"
void thayTheChildBangChildren(vector<string>& words) {
    for (string& word : words) {
        if (word == "child") {
            word = "children";
        }
    }
}

// Hàm tách chuỗi thành các từ và lưu vào vector
vector<string> tachCacTu(const string& text) {
    vector<string> words;
    stringstream ss(text);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

// Hàm chuyển vector các từ về lại thành chuỗi
string vectorToString(const vector<string>& words) {
    string result;
    for (const string& word : words) {
        result += word + " ";
    }
    result.pop_back(); // Xóa dấu cách thừa ở cuối
    return result;
}

int main() {
    string text;
    cout << "Nhập đoạn văn bản tiếng Anh (không quá 50 từ): ";
    getline(cin, text);
    
    // Tách đoạn văn bản thành các từ
    vector<string> words = tachCacTu(text);
    
    // Kiểm tra nếu có quá 50 từ
    if (words.size() > 50) {
        cout << "Đoạn văn bản có quá 50 từ, vui lòng nhập lại!" << endl;
        return 0;
    }

    // Đếm số lần xuất hiện từ "child"
    int count = demSoLanXuatHienChild(words);
    cout << "Có " << count << " lần xuất hiện từ \"child\" trong đoạn văn bản." << endl;

    // Thay thế tất cả các từ "child" thành "children"
    thayTheChildBangChildren(words);

    // Chuyển vector các từ thành chuỗi và in ra
    string updatedText = vectorToString(words);
    cout << "Đoạn văn bản sau khi thay thế: " << endl;
    cout << updatedText << endl;

    return 0;
}
