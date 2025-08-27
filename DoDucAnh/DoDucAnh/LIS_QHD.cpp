#include <bits/stdc++.h>
using namespace std;

// Hàm tìm dãy con tăng dần dài nhất (LIS) trong chuỗi s và in ra chuỗi đó
void qhd(string s) {
    int n = s.length(); // Độ dài chuỗi s
    vector<int> F(n, 1);     // F[i]: độ dài LIS kết thúc tại vị trí i (khởi tạo = 1)
    vector<int> prev(n, -1); // prev[i]: chỉ số phần tử đứng trước i trong LIS (truy vết)

    // Tính mảng F và mảng prev
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // Nếu s[j] <= s[i] và việc nối s[i] vào LIS kết thúc ở j làm LIS dài hơn
            if (s[j] <= s[i] && F[i] < F[j] + 1) {
                F[i] = F[j] + 1;   // Cập nhật độ dài LIS tại i
                prev[i] = j;      // Ghi nhớ vị trí trước đó để truy vết
            }
        }
    }

    // In thử mảng F (độ dài LIS tại mỗi vị trí) – chỉ để debug
    for (auto i : F) cout << i << endl;

    // Tìm độ dài lớn nhất của LIS
    int max_len = *max_element(F.begin(), F.end());
    cout << n << " Do dai LIS: " << max_len << endl;

    // Tìm vị trí kết thúc của LIS (nơi độ dài là lớn nhất)
    int idx = max_element(F.begin(), F.end()) - F.begin();
    cout << "     " << idx << endl; // In ra chỉ số kết thúc của LIS

    vector<char> lis; // Dùng để lưu chuỗi LIS

    // Truy vết ngược lại để xây dựng chuỗi LIS
    while (idx != -1) {
        lis.push_back(s[idx]); // Lưu ký tự hiện tại
        idx = prev[idx];       // Lùi về phần tử trước trong LIS
    }

    // Đảo ngược để in ra chuỗi đúng thứ tự gốc
    reverse(lis.begin(), lis.end());

    // In ra chuỗi con tăng dần dài nhất (LIS)
    cout << "Chuoi con tang dan LIS: ";
    for (char c : lis) {
        cout << c;
    }
    cout << endl;
}

int main() {
    string s = "sfbjdsbjwqiexmazaiwpoa";
    qhd(s);        // Gọi hàm xử lý LIS
    return 0;
}
