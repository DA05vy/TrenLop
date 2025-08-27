#include <bits/stdc++.h>
using namespace std;

int chiatri(vector<int> &a, int left, int right, int k) {
    if (left > right) {
        return -1;  // Trường hợp không tìm thấy phần tử
    }

    int mid = left + (right - left) / 2; // Tính giữa mảng
    if (a[mid] == k) {
        return mid;
    } else if (a[mid] < k) {
        return chiatri(a, mid + 1, right, k); // Tìm trong nửa phải
    } else {
        return chiatri(a, left, mid - 1, k); // Tìm trong nửa trái
    }
}

int timmax( vector<int> &a, int left, int right ){
  if ( left == right ){
    return a[left];
  }
  
  int mid = ( left + right )/2;
  int leftmax = timmax( a, left, mid );
  int rightmax = timmax( a, mid + 1, right);
  if ( leftmax <= rightmax ){
    return rightmax;
  } else {
    return leftmax;
  }
}

int luy( int n, int k ){
  if ( k== 0 ){
    return 1;
  }
  if ( k == 1 ){
    return n;
  }
  if ( k % 2 != 0 ){
    int half = luy(n, k/2);
    return n * half * half;
  } else {
    int half = luy(n, k/2);
    return half * half;
  }
}

int main() {
  
    srand(time(0));
    // Sinh kích thước ngẫu nhiên từ 10 đến 30
    int n = rand() % 21 + 10;
    vector<int> a(n);

    // Sinh mảng ngẫu nhiên
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 41 + 1; // Sinh giá trị ngẫu nhiên từ 1 đến 41
    }

    // In mảng ban đầu
    for (auto i : a) cout << i << " ";
    cout << endl;

    // Sinh số k ngẫu nhiên để tìm kiếm
    int k = rand() % 41 + 1; 
    cout << "Tìm kiếm: " << k << endl;
    
    
    cout << timmax(a,0,n-1) << endl;
    

    // Sắp xếp mảng
    sort(a.begin(), a.end());

    // In mảng sau khi sắp xếp
    for (auto i : a) cout << i << " ";
    cout << endl;

    // Tìm kiếm chỉ số của k trong mảng
    int result = chiatri(a, 0, n - 1, k);
    
    if (result != -1) {
        cout << "Chỉ số của " << k << " là: " << result << endl;
    } else {
        cout << "Không tìm thấy " << k << " trong mảng." << endl;
    }
    
    cout << luy(k,n) << endl;

    return 0;
}
