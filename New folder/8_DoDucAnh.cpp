#include <iostream>
#include <vector>

// Sử dụng namespace std để không cần gõ "std::"
using namespace std;

// Biến toàn cục để lưu ma trận đồ thị và mảng đánh dấu đã thăm
vector<vector<int>> O;
vector<vector<bool>> flag; // Mảng đánh dấu các ô đã thăm (visited)

// Biến toàn cục để lưu kích thước của ma trận
int num_rows;
int num_cols;

// Thuật toán loang (DFS)
// i: chỉ số hàng hiện tại
// j: chỉ số cột hiện tại
void loang(int i, int j) {
    flag[i][j] = true; // Đánh dấu ô hiện tại đã được thăm

    // Loang sang ô bên trái
    if (j > 0) { // Kiểm tra biên
        if ((O[i][j-1] == O[i][j]) && (!flag[i][j-1])) { // Nếu cùng giá trị và chưa thăm
            loang(i, j - 1);
        }
    }

    // Loang ô bên trên
    if (i > 0) { // Kiểm tra biên
        if ((O[i-1][j] == O[i][j]) && (!flag[i-1][j])) { // Nếu cùng giá trị và chưa thăm
            loang(i - 1, j);
        }
    }

    // Loang ô bên phải
    if (j < num_cols - 1) { // Kiểm tra biên
        if ((O[i][j+1] == O[i][j]) && (!flag[i][j+1])) { // Nếu cùng giá trị và chưa thăm
            loang(i, j + 1);
        }
    }

    // Loang ô bên dưới
    if (i < num_rows - 1) { // Kiểm tra biên
        if ((O[i+1][j] == O[i][j]) && (!flag[i+1][j])) { // Nếu cùng giá trị và chưa thăm
            loang(i + 1, j);
        }
    }
}

int main() {
    // Ví dụ ma trận đồ thị
    O = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1}
    };

    num_rows = O.size();
    if (num_rows > 0) {
        num_cols = O[0].size();
    } else {
        num_cols = 0;
    }

    // Khởi tạo mảng flag với tất cả là false (chưa thăm)
    flag.assign(num_rows, vector<bool>(num_cols, false));

    cout << "Ma tran do thi:" << endl;
    for (int r = 0; r < num_rows; ++r) {
        for (int c = 0; c < num_cols; ++c) {
            cout << O[r][c] << " ";
        }
        cout << endl;
    }

    int connectedComponentsCount = 0;

    // Duyệt qua tất cả các ô trong ma trận
    for (int r = 0; r < num_rows; ++r) {
        for (int c = 0; c < num_cols; ++c) {
            // Nếu ô hiện tại chưa được thăm
            if (!flag[r][c]) {
                connectedComponentsCount++; // Tăng số lượng miền liên thông
                loang(r, c); // Bắt đầu loang từ ô này
            }
        }
    }

    cout << "So luong mien lien thong la: " << connectedComponentsCount << endl;
    cout << "--------------------------------------------------" << endl;
    return 0;
}
