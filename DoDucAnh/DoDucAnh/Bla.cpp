#include <bits/stdc++.h>

using namespace std;

#define int long long

class Fan {
  public:
    string t;
    string m;
    long long g;
    
    Fan(string b, string c, long long p) : t(b), m(c), g(p) {}
    
    void display(){
      cout << t << " " << m << " " << g << endl;
    }
};

bool compare( Fan &a, Fan &b ){
  return a.g < b.g;
}



void sell( int p, vector<Fan> fans ){
  sort(fans.begin(), fans.end(), compare);
  
  long long total = 0;
  vector<Fan> soldfans;
  
  for ( auto &fan: fans){
    if ( total + fan.g <= p ){
      soldfans.push_back(fan);
      total += fan.g;
    }
  }
  
  cout << p << endl;
  cout << total << endl;
  for ( auto &fan: soldfans ){
    fan.display();
  }
  cout << soldfans.size() << endl;
}


signed main(){
  srand(time(0));
  int p = rand() % 1200001;
  
  vector<string> brands = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  vector<string> colors = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  vector<Fan> Fans;
  for ( int i = 0; i < brands.size(); i++ ){
    long long gia = rand() % 400001;
    Fans.push_back(Fan(brands[i], colors[i], gia));
  }
  
  sell(p, Fans);
  return 0;
}



//Andre



#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const int MAX_N = 100;  // Giới hạn n
const int MAX_M = 100;  // Giới hạn m

int f[MAX_N+1][MAX_M+1] = {0};  // Khởi tạo mảng tĩnh

void solution(int n, int m) {
    // Khởi tạo cơ bản: Số cách để có tổng = 0 là 1 (chọn không phần tử)
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i][0] = 0; // Không có cách để có tổng = 0 trừ khi chọn không phần tử
    }

    // Tính số cách phân tích n thành tổng của các số nhỏ hơn hoặc bằng m
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= i) {
                f[j][i] = f[j - i][i] + f[j][i - 1]; // Sử dụng số i
            } else {
                f[j][i] = f[j][i - 1]; // Không thể sử dụng số i
            }
        }
    }

    // In bảng DP (không bắt buộc)
    cout << "Bảng DP:" << endl;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << f[j][i] << " ";
        }
        cout << endl;
    }

    cout << "Số cách phân tích " << n << " là: " << f[n][m] << endl;
}

void printCombinations(int n, int m, vector<int>& current, int start) {
    // Nếu tổng đã đạt tới n, in kết quả
    if (n == 0) {
        for (int i = 0; i < current.size(); i++) {
            cout << current[i] << " ";
        }
        cout << endl;
        return;
    }

    // Duyệt từ start đến m
    for (int i = start; i <= m; i++) {
        if (i <= n) {
            current.push_back(i);
            printCombinations(n - i, m, current, i);  // Phép quay lui, cho phép lặp lại i
            current.pop_back();  // Quay lại, thử số khác
        }
    }
}

int main() {
    srand(time(0));  // Khởi tạo bộ sinh số ngẫu nhiên

    int n = rand() % 51 + 5;  // n là một số ngẫu nhiên từ 5 đến 55
    int m = rand() % 51 + 5;  // m là một số ngẫu nhiên từ 5 đến 55

    cout << "n = " << n << ", m = " << m << endl;  // In giá trị n và m ngẫu nhiên

    solution(n, m); // Gọi hàm tính số cách

    cout << "Các cách phân tích " << n << " thành tổng của các số <= " << m << " là: " << endl;
    vector<int> current;
    printCombinations(n, m, current, 1);  // Bắt đầu từ số 1 để liệt kê các cách
    return 0;
}

//Andre

#include <bits/stdc++.h>

using namespace std;

#define int long long

class Fan {
  public:
    string t;
    string m;
    long long g;
    
    Fan(string b, string c, long long p) : t(b), m(c), g(p) {}
    
    void display(){
      cout << t << " " << m << " " << g << endl;
    }
};

bool compare( Fan &a, Fan &b ){
  return a.g < b.g;
}



void sell( int p, vector<Fan> fans ){
  sort(fans.begin(), fans.end(), compare);
  
  long long total = 0;
  vector<Fan> soldfans;
  
  for ( auto &fan: fans){
    if ( total + fan.g <= p ){
      soldfans.push_back(fan);
      total += fan.g;
    }
  }
  
  cout << p << endl;
  cout << total << endl;
  for ( auto &fan: soldfans ){
    fan.display();
  }
  cout << soldfans.size() << endl;
}


signed main(){
  srand(time(0));
  int p = rand() % 1200001;
  
  vector<string> brands = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  vector<string> colors = {"A", "B", "C", "D", "E", "F", "G", "H", "I"};
  vector<Fan> Fans;
  for ( int i = 0; i < brands.size(); i++ ){
    long long gia = rand() % 400001;
    Fans.push_back(Fan(brands[i], colors[i], gia));
  }
  
  sell(p, Fans);
  return 0;
}


//Andre



#include <bits/stdc++.h>
using namespace std;

void lis ( int n, int m, string a, string b ){
  vector<vector<int>> dp ( n+1, vector<int>(m+1,0));
  
  for ( int i = 1; i <= n; i++ ){
    for ( int j = 1; j <= m; j++ ){
      if ( a[i-1] == b[j-1] ){
        dp[i][j] = dp[i-1][j-1] + 1; 
      } else {
        dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
      }
    }
  }
  
  cout << dp[n][m] << endl;
  vector<char> lcs;
  int i = n, j = m;
  while( i > 0 && j > 0 ){
    if( a[i-1] == b[j-1] ){
      lcs.push_back(a[i-1]);
      i--;
      j--;
    } else if ( dp[i-1][j] >= dp[i][j-1] ){
      i--;
    } else {
      j--;
    }
  }
  
  reverse(lcs.begin(), lcs.end());
  for ( auto i : lcs ){
    cout << i;
  }
}

signed main(){
  string a,b;
  a = "udisfidksh";
  b = "doishfoishfoi";
  lis( a.length(), b.length(), a,b );
  return 0;
}


//Andre


#include <bits/stdc++.h>
using namespace std;

class Workshop {
public:
    string topic;  // Chủ đề hội thảo
    int start_time;  // Thời gian bắt đầu
    int end_time;  // Thời gian kết thúc

    Workshop(string t, int s, int e) : topic(t), start_time(s), end_time(e) {}
};

// Hàm sắp xếp các hội thảo theo thời gian kết thúc
bool compare(Workshop &a, Workshop &b) {
    return a.end_time < b.end_time;
}

void maxWorkshops(int n, vector<Workshop> &workshops) {
    // Sắp xếp các hội thảo theo thời gian kết thúc
    sort(workshops.begin(), workshops.end(), compare);

    int count = 0;  // Số lượng hội thảo có thể tham gia
    vector<Workshop> selected_workshops;  // Danh sách các hội thảo đã chọn

    int last_end_time = -1;  // Thời gian kết thúc của hội thảo trước đó

    for (int i = 0; i < n; ++i) {
        // Nếu hội thảo bắt đầu sau thời gian kết thúc của hội thảo trước đó
        if (workshops[i].start_time >= last_end_time) {
            selected_workshops.push_back(workshops[i]);
            last_end_time = workshops[i].end_time;
            count++;
        }
    }

    // In ra kết quả
    cout << "Số lượng hội thảo sinh viên có thể tham gia: " << count << endl;
    cout << "Danh sách các hội thảo sinh viên có thể tham gia:" << endl;
    for (auto &workshop : selected_workshops) {
        cout << "Chủ đề: " << workshop.topic << ", Thời gian: " << workshop.start_time << " - " << workshop.end_time << endl;
    }
}

int main() {
    int n;
    cout << "Nhập số lượng hội thảo: ";
    cin >> n;

    vector<Workshop> workshops;

    // Nhập thông tin các hội thảo
    for (int i = 0; i < n; ++i) {
        string topic;
        int start_time, end_time;
        cout << "Nhập thông tin hội thảo thứ " << i + 1 << endl;
        cout << "Chủ đề: ";
        cin >> ws;  // Xóa bỏ khoảng trắng thừa
        getline(cin, topic);
        cout << "Thời gian bắt đầu: ";
        cin >> start_time;
        cout << "Thời gian kết thúc: ";
        cin >> end_time;

        workshops.push_back(Workshop(topic, start_time, end_time));
    }

    // Gọi hàm tìm số hội thảo và danh sách hội thảo có thể tham gia
    maxWorkshops(n, workshops);

    return 0;
}