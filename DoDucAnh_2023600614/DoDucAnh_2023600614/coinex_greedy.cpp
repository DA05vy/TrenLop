#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm giải quyết bài toán đổi tiền bằng thuật toán tham lam
bool CASHIERS_ALGORITHM(vector<int> &C, int m, long n, vector<int> &S) {
  // Khởi tạo số lượng đồng tiền cho mỗi loại là 0
  fill(S.begin(), S.end(), 0);
  
  int i = 0;
  while (n > 0 && i < m) {
    S[i] = n / C[i];    // Số lượng đồng tiền loại C[i]
    n = n % C[i];       // Cập nhật số tiền còn lại
    ++i;
  }
  
  if (n > 0) return false;  // Nếu còn tiền không thể đổi được, trả về false
  return true;
}

int main() {
    vector<int> C = { 1, 2, 5, 10, 20, 50, 100 };  // Các mệnh giá tiền
    sort(C.rbegin(), C.rend());
    int m = 7;  // Số lượng mệnh giá tiền
    long n = 125;  // Số tiền cần đổi
    vector<int> S(100);  // Mảng lưu số lượng đồng tiền của mỗi loại

    if (CASHIERS_ALGORITHM(C, m, n, S)) {
        cout << "Có thể đổi tiền, số lượng mỗi loại đồng tiền là: " << endl;
        for (int i = 0; i < m; ++i) {
            if (S[i] > 0) {
                cout << "Mệnh giá " << C[i] << ": " << S[i] << " đồng" << endl;
            }
        }
    } else {
        cout << "Không thể đổi số tiền này với các mệnh giá có sẵn." << endl;
    }
    return 0;
}
