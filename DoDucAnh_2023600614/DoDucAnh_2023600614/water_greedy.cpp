#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxBottlesFilled(vector<int> &C, int m, long n, vector<int> &filledBottles)
{
  int filled = 0;
  for (int i = 0; i < m; ++i) {
    if (n >= C[i]) {
      n -= C[i];          // Trừ đi lượng chất lỏng đã dùng
      filled++;           // Tăng số chai đã đổ đầy
      filledBottles.push_back(C[i]);  // Lưu trữ dung tích chai đã dùng
    } else {
      break;  // Dừng lại nếu không đủ chất lỏng để đổ đầy chai hiện tại
    }
  }
  return filled;  // Trả về tổng số chai đã đổ đầy
}

int main(){
  vector<int> C = {5, 7, 10, 4, 8};  // Dung tích các chai
  sort(C.begin(), C.end());  // Sắp xếp dung tích chai
  vector<int> filledBottles;  // Vector để lưu trữ dung tích chai đã sử dụng

  int m = 5;  // Số lượng loại chai
  long n = 20;  // Lượng chất lỏng

  int totalFilled = maxBottlesFilled(C, m, n, filledBottles);  // Gọi hàm để đổ đầy chai

  cout << "Total bottles filled: " << totalFilled << endl;
  cout << "Bottles used: ";
  for (int bottle : filledBottles) {
    cout << bottle << " ";  // In ra dung tích của từng chai đã sử dụng
  }
  cout << endl;

  return 0;
}
