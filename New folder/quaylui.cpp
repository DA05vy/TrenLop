#include<bits/stdc++.h>
using namespace std;

vector<int> x;
vector<int> dd;

void inkq(){
  // In kết quả hoán vị
  for ( auto i : x ) cout << i << " ";
  cout << endl;
}

void hoanvi(int k, int n){
  // Hàm đệ quy sinh hoán vị
  for ( int i = 1; i <= n; i++ ){
    if ( dd[i] == 0 ){  // Kiểm tra phần tử chưa được chọn
      x[k] = i;         // Chọn phần tử i cho vị trí k
      if ( k == n - 1 ){ // Khi k đã đến cuối mảng, in kết quả
        inkq();
      } else {
        dd[i] = 1;        // Đánh dấu phần tử i là đã chọn
        hoanvi(k + 1, n); // Gọi đệ quy cho vị trí kế tiếp
        dd[i] = 0;        // Quay lại và bỏ đánh dấu cho phần tử i
      }
    }
  }
}

void nhiphan(int k, int n ){
  for ( int i = 0; i <= 1; i++ ){
    x[k] = i;
    if ( k == n - 1 ){
      inkq();
    } else {
      nhiphan( k+1, n);
    }
  }
}

void tohop(int i, int k, int n) {
  for (int j = x[i - 1] + 1; j <= n - k + i; j++) {
    x[i] = j;
    if (i == k) {
      inkq(); // Khi đã chọn đủ k phần tử, in kết quả
    } else {
      tohop(i + 1, k, n); // Đệ quy để chọn phần tử tiếp theo
    }
  }
}


int main(){
  srand(time(0));
  
  int n = rand() % 6 + 2;  // Chọn n ngẫu nhiên trong khoảng [2, 10]
  
  dd.assign(n + 1, 0);      // Khởi tạo dd với n + 1 phần tử, tất cả bằng 0
  
  x.resize(n);              // Đảm bảo vector x có kích thước đúng
  
  //cout << "Hoán vị của " << n << " phần tử: \n";
  //hoanvi(0, n);             // Gọi hàm hoán vị
  
  //nhiphan(0, n); 
  
  int k = rand() % 4 + 1;
  x.resize(k + 1); // Resize vector x đủ lớn để chứa k phần tử
  
  tohop(1, k, n);  // Gọi hàm tạo tổ hợp

  return 0;
}
