/*
→ Mỗi vị trí là một bước trong đệ quy (vị trí k = 0 → 5 vì ta chọn 6 ký tự)

→ Ở mỗi bước k, ta:
   - Duyệt qua từng chữ cái trong tập S (gồm 7 ký tự từ 'A' đến 'G')
   - Nếu chữ cái i chưa được dùng:
       + Gán chữ cái i vào vị trí k của tổ hợp
       + Đánh dấu chữ cái i là đã dùng (used[i] = true)
       + Gọi đệ quy xử lý vị trí tiếp theo (k + 1)

       + Khi quay lui xảy ra (sau khi xử lý xong đệ quy ở k+1):
           → Tức là đã thử xong 1 nhánh hoặc cần thử nhánh khác
           → Bỏ đánh dấu used[i] = false (trả lại trạng thái ban đầu)
           → Để thử chữ cái khác ở cùng vị trí hiện tại

→ Khi k == 6 (tức đã chọn đủ 6 ký tự):
   - In ra 1 tổ hợp hợp lệ (vì đây là một tổ hợp gồm 6 ký tự khác nhau từ tập 7 ký tự ban đầu)

MINH HỌA QUÁ TRÌNH QUAY LUI

Vị trí 0: A
│
├── Vị trí 1: B
│   ├── Vị trí 2: C
│   │   └── Vị trí 3: D
│   │       └── Vị trí 4: E
│   │           └── Vị trí 5: F   → [A, B, C, D, E, F]
│   │           └── Vị trí 5: G   → [A, B, C, D, E, G]
│   ├── Vị trí 2: D
│   └── ...
├── Vị trí 1: C
│   └── ...
└── Vị trí 1: D
    └── ...

→ Khi đã xét hết các nhánh ở vị trí k nào đó:
   - Quay lui về vị trí k - 1 để thử phần tử khác chưa dùng tại vị trí đó
*/



#include <iostream>
#include <vector>
using namespace std;

const int N = 7;
char S[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

bool used[N] = {false};          // Đánh dấu ký tự đã dùng
char result[6];        // Kết quả tạm thời
int count_result = 0;  // Biến đếm số cách sinh ra

// Hàm quay lui để chọn 6 ký tự
void backtrack(int k) {
    // Nếu đã chọn đủ 6 ký tự → in kết quả
    if (k == 6) {
        for (int i = 0; i < 6; ++i)
            cout << result[i] << " ";
        cout << endl;
        ++count_result;
        return;
    }

    // Duyệt qua từng ký tự trong S
    for (int i = 0; i < N; ++i) {
        if (!used[i]) {
            result[k] = S[i];  // Gán ký tự S[i] vào vị trí k
            used[i] = true;    // Đánh dấu đã dùng

            backtrack(k + 1);  // Gọi đệ quy xử lý vị trí tiếp theo

            used[i] = false;   // Bỏ đánh dấu sau khi quay lui
        }
    }
}

int main() {
    backtrack(0);
    cout << "Tong so cach chon: " << count_result << endl;
    return 0;
}
