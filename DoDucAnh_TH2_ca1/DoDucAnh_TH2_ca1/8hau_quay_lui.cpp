#include<iostream>
#define SIZE 8  // Kích thước bàn cờ (Số lượng quân Hậu là SIZE)
using namespace std;

int queens[SIZE];  // Mảng lưu vị trí của các quân Hậu, queens[i] là cột của quân Hậu ở hàng i.

void output(){
    // In ra bàn cờ với các quân Hậu
    for ( int i = 0; i < SIZE; i++ ){
        for ( int j = 0; j < SIZE; j++ ){
            if (queens[i] == j){  // Nếu vị trí của quân Hậu ở hàng i là cột j
                cout << "*" << " ";  // In ra ký tự "*" để đại diện cho quân Hậu
            } else {
                cout << "0" << " ";  // In ra "0" cho các ô không có quân Hậu
            }
        }
        cout << endl;
    }

    // Hỏi người dùng có muốn tiếp tục tìm kiếm các kết quả tiếp theo không
    cout << "KQ tiep theo (y/n)?";
    if (getchar() == 'y'){  // Nếu người dùng nhập 'y' thì tiếp tục, ngược lại kết thúc chương trình
        cin.ignore(1);  // Bỏ qua ký tự mới dòng vừa nhập
        cout << "--------" << endl;  // In dấu phân cách
    } else {
        exit(1);  // Thoát chương trình
    }
}

bool canPutQueen(int i, int j){
    // Hàm kiểm tra xem có thể đặt quân Hậu vào vị trí (i, j) hay không
    for (int k = 0; k < i; k++){
        // Kiểm tra xem quân Hậu đã được đặt trên cùng hàng, cùng cột hoặc cùng đường chéo chưa
        if (queens[k] == j || abs(k - i) == abs(queens[k] - j)){
            return false;  // Nếu đã có quân Hậu ở vị trí này thì không thể đặt vào (i, j)
        }
    }
    return true;  // Nếu chưa có quân Hậu nào có thể tấn công vào vị trí này thì có thể đặt quân Hậu
}

void putQueens(int idx){
    // Hàm quay lui để đặt quân Hậu vào từng vị trí hợp lệ
    for (int j = 0; j < SIZE; j++){
        // Duyệt qua tất cả các cột để thử đặt quân Hậu ở từng vị trí
        if (canPutQueen(idx, j) == true){  // Nếu có thể đặt quân Hậu ở hàng idx và cột j
            queens[idx] = j;  // Đặt quân Hậu vào vị trí (idx, j)
            if (idx == SIZE - 1){  // Nếu đã đặt quân Hậu vào hàng cuối cùng
                output();  // In ra bàn cờ đã đặt tất cả các quân Hậu
            } else {
                putQueens(idx + 1);  // Gọi đệ quy để tiếp tục đặt quân Hậu vào hàng tiếp theo
            }
            queens[idx] = 0;  // Quay lui, gỡ quân Hậu ra khỏi vị trí này để thử các vị trí khác
        }
    }
}

int main(){
    // Chạy đệ quy từ hàng đầu tiên (idx = 0)
    putQueens(0);
    return 0;
}
