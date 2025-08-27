#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Hàm tạo bảng dịch chuyển cho thuật toán Boyer-Moore-Horspool
void createBadCharacterTable(const string &P, vector<int> &badCharTable) {
    int m = P.length();
    
    // Khởi tạo bảng dịch chuyển với giá trị mặc định là m (chỉ số dài nhất của P)
    for (int i = 0; i < 256; i++) {  // Duyệt qua tất cả các ký tự ASCII
        badCharTable[i] = m;
    }
    
    // Điền giá trị cho bảng dịch chuyển dựa trên xâu mẫu P
    for (int i = 0; i < m - 1; i++) { // Mới cập nhật các giá trị ngoại trừ ký tự cuối cùng của P
        badCharTable[(int)P[i]] = m - i - 1;
    }
}

// Hàm Boyer-Moore-Horspool tìm kiếm xâu Q trong xâu P
bool Boyer_Moore_Horspool(const string &P, const string &Q) {
    int n = P.length();
    int m = Q.length();
    
    // Nếu xâu mẫu dài hơn xâu mẹ, không thể tìm kiếm
    if (m > n) {
        return false;
    }
    
    // Tạo bảng dịch chuyển
    vector<int> badCharTable(256, 0); // Bảng dịch chuyển cho tất cả các ký tự ASCII
    createBadCharacterTable(Q, badCharTable);
    
    int i = m - 1;  // Bắt đầu so sánh từ cuối của xâu mẫu Q và xâu mẹ P
    while (i < n) {
        int k = m - 1;
        
        // So sánh từ phải qua trái
        while (k >= 0 && P[i - (m - 1 - k)] == Q[k]) {
            k--;
        }
        
        if (k < 0) {
            // Nếu k < 0, có nghĩa là xâu mẫu Q đã khớp tại vị trí i - (m-1)
            return true;
        } else {
            // Nếu không khớp, dịch chuyển xâu mẫu theo bảng dịch chuyển
            i += badCharTable[(int)P[i]];
        }
    }
    
    return false;
}

int main() {
    string P, Q;
    
    // Nhập chuỗi mẹ (P) và chuỗi con (Q)
    cout << "Nhập chuỗi P (chuỗi mẹ): ";
    getline(cin, P);
    
    cout << "Nhập chuỗi Q (chuỗi con): ";
    getline(cin, Q);
    
    // Kiểm tra xem chuỗi Q có phải là chuỗi con của chuỗi P không
    if (Boyer_Moore_Horspool(P, Q)) {
        cout << "Chuỗi Q là chuỗi con của chuỗi P.\n";
    } else {
        cout << "Chuỗi Q không phải là chuỗi con của chuỗi P.\n";
    }
    
    return 0;
}
