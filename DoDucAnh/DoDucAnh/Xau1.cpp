#include <iostream>
#include <string>
using namespace std;

// Hàm kiểm tra xâu có phải đối xứng hay không
bool kiemTraDoiXung(string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

// Hàm tìm xâu con đối xứng dài nhất có tâm tại chỉ số k
string timXauConDoiXung(string& s, int k) {
    int n = s.length();
    int left = k, right = k;
    
    // Mở rộng từ tâm k cho đến khi không còn đối xứng
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    
    // Xâu con đối xứng là từ left + 1 đến right - 1
    return s.substr(left + 1, right - left - 1);
}

int main() {
    string s = "meoefhdgkeoem";

    // Kiểm tra xâu có phải đối xứng không
    if (kiemTraDoiXung(s)) {
        cout << "Xâu là đối xứng." << endl;
    } else {
        int k;
        cout << "Nhập chỉ số k: ";
        cin >> k;

        // Kiểm tra k có hợp lệ không
        if (k >= 0 && k < s.length()) {
            string xauCon = timXauConDoiXung(s, k);
            cout << "Xâu con đối xứng dài nhất có tâm tại s[" << k << "]: " << xauCon << endl;
        } else {
            cout << "Chỉ số k không hợp lệ." << endl;
        }
    }

    return 0;
}
