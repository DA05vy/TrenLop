#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> x;  // Đổi thành vector để dễ dàng xử lý.

void inkq() {
  for (int i = 1; i <= k; i++) {
    cout << x[i] << " ";
  }
  cout << endl;
}

void hoanvi(int i, int n, int k) {
  // Tạo ra các hoán vị từ i-th vị trí đến k-th vị trí
  for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
    x[i] = j;  // Gán giá trị cho vị trí thứ i
    if (i == k) {  // Khi đã đi đến vị trí cuối cùng, in kết quả
      inkq();
    } else {  // Nếu chưa, tiếp tục đệ quy
      hoanvi(i + 1, n, k);
    }
  }
}

int main() {
  cin >> n >> k;  // Nhập vào n và k
  x.assign(k + 1, 0);  // Đảm bảo x có kích thước k + 1, khởi tạo bằng 0
  hoanvi(1, n, k);  // Bắt đầu từ vị trí 1
  return 0;
}
