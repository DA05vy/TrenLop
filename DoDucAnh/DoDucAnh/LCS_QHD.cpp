#include<bits/stdc++.h>
using namespace std;

// Hàm tính và truy vết Longest Common Subsequence (LCS) giữa hai chuỗi a và b
void qhd(string a, string b) {
    int n = a.length();
    int m = b.length();

    // Tạo bảng 2 chiều f, f[i][j] lưu độ dài LCS của a[0..i-1] và b[0..j-1]
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    // Tính bảng f theo quy tắc:
    // Nếu ký tự a[i-1] == b[j-1], thì f[i][j] = f[i-1][j-1] + 1
    // Ngược lại, lấy max của f[i-1][j] và f[i][j-1]
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }

    // In bảng f để kiểm tra (có thể comment nếu không cần)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }

    // In độ dài LCS
    cout << "\nDo dai LCS: " << f[n][m] << endl;

    // Truy vết từ f[n][m] xuống f[0][0] để tìm chuỗi con chung dài nhất
    string lcs = "";  // Biến lưu chuỗi LCS
    int i = n, j = m;

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            // Nếu ký tự tại a[i-1] và b[j-1] giống nhau, ký tự đó thuộc LCS
            lcs += a[i - 1];
            i--;
            j--;
        }
        else {
            // Nếu khác nhau, đi theo hướng có giá trị lớn hơn trong bảng f
            if (f[i - 1][j] > f[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }

    // LCS được tạo ra từ cuối lên đầu nên phải đảo ngược lại
    reverse(lcs.begin(), lcs.end());

    // In chuỗi con chung dài nhất (LCS)
    cout << "Chuoi con chung dai nhat (LCS): " << lcs << endl;
}

int main() {
    string a, b;
    // Nhập 2 chuỗi a và b
    cin >> a >> b;

    // Gọi hàm tính và truy vết LCS
    qhd(a, b);

    return 0;
}
