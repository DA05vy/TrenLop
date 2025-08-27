#include <bits/stdc++.h>

using namespace std;

bool solve_knight_tour(int n) {
    // Khởi tạo bàn cờ với các giá trị ban đầu bằng 0
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Các bước di chuyển hợp lệ của con mã
    vector<pair<int, int>> moves = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                                    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

    // Hàm kiểm tra xem một bước di chuyển có hợp lệ không
    auto is_valid_move = [&](int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n)
            return false;
        if (board[x][y] != 0)
            return false;
        return true;
    };

    // Hàm thực hiện thuật toán quay lui
    function<bool(int, int, int)> backtrack = [&](int x, int y, int count) {
        if (count == n*n)
            return true;
        for (auto move : moves) {
            int next_x = x + move.first;
            int next_y = y + move.second;
            if (is_valid_move(next_x, next_y)) {
                board[next_x][next_y] = count + 1;
                if (backtrack(next_x, next_y, count + 1))
                    return true;
                board[next_x][next_y] = 0;
            }
        }
        return false;
    };

    // Bắt đầu tìm kiếm
    board[0][0] = 1;
    if (backtrack(0, 0, 1)) {
        // Nếu tìm thấy đường đi hợp lệ, in ra bàn cờ
        for (auto row : board) {
            for (auto cell : row)
                cout << cell << " ";
            cout << endl;
        }
        return true;
    } else {
        cout << "Không tìm thấy đường đi hợp lệ." << endl;
        return false;
    }
}

int main() {
    int n = 8;
    solve_knight_tour(n);
    return 0;
}
