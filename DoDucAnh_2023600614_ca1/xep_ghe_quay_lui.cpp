/*
→ Mỗi ghế là một bước trong đệ quy (vị trí k = 0 → 3)

→ Ở mỗi bước k, ta:
   - Duyệt qua từng người (từ 0 → 3)
   - Nếu người i chưa được dùng:
       + Gán người i vào ghế k
       + Đánh dấu người i là đã dùng
       + Gọi đệ quy xử lý ghế tiếp theo (k + 1)

       + Khi quay lui xảy ra (sau khi quay về từ đệ quy k+1):
           → Tức là ta đã thử xong nhánh đó hoặc cần thử nhánh khác
           → Ta cần **bỏ đánh dấu người i** (used[i] = false)
           → Nhằm trả lại trạng thái ban đầu để thử người khác cho ghế k

→ Khi k == 4 (tức đã gán đủ 4 ghế):
   - In ra 1 cách xếp hợp lệ (vì đây là một hoán vị hoàn chỉnh)

VÍ DỤ

Ghế A (vị trí 0) → tung
Ghế B (vị trí 1) → cuc
Ghế C (vị trí 2) → truc
Ghế D (vị trí 3) → mai
→ In: [A:tung, B:cuc, C:truc, D:mai]

Sau đó thuật toán quay lại ghế D, thử người khác chưa dùng,
nếu hết người thì quay lại ghế C, và tiếp tục...

MINH HỌA

Ghế 0: tung
│
├── Ghế 1: cuc
│   ├── Ghế 2: truc
│   │   └── Ghế 3: mai   → [tung, cuc, truc, mai]
│   └── Ghế 2: mai
│       └── Ghế 3: truc → [tung, cuc, mai, truc]
├── Ghế 1: truc
│   └── ...
├── Ghế 1: mai
    └── ...
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ghe = {"A", "B", "C", "D"};
vector<string> nguoi = {"tung", "cuc", "truc", "mai"};

int n = 4;
bool used[4] = {false};  // Đánh dấu người đã dùng
string xep[4];           // Lưu kết quả sắp xếp
int count = 0;           // Đếm số cách

void backtrack(int k) {
    if (k == n) {
        // In ra 1 cách xếp
        cout << "Cách " << count + 1 << ": ";
        for (int i = 0; i < n; i++) {
            cout << ghe[i] << ":" << xep[i] << " ";
        }
        cout << endl;
        count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            xep[k] = nguoi[i];   // Gán người i vào ghế k
            used[i] = true;
            backtrack(k + 1);    // Đệ quy cho ghế tiếp theo
            used[i] = false;     // Quay lui
        }
    }
}

int main() {
    backtrack(0);
    cout << "\nTổng số cách xếp: " << count << endl;
    return 0;
}
