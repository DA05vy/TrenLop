#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Cấu trúc công việc
struct CongViec {
    string ma;         // Mã công việc
    string batDau;     // Thời gian bắt đầu (HH:MM)
    int thoiGian;      // Thời gian thực hiện (phút)
};

// Danh sách công việc 
vector<CongViec> ds = {
    {"CV01", "08:00", 60},   
    {"CV02", "09:15", 90}, 
    {"CV03", "11:00", 45},  
    {"CV04", "13:30", 120}, 
    {"CV05", "15:45", 30},   
    {"CV06", "16:30", 60},   
    {"CV07", "17:45", 45},  
};

/*
 Hàm inNguoc - sử dụng thuật toán đệ quy (recursion)
 → In danh sách công việc từ cuối danh sách lên đầu.
 → Mỗi lần gọi đệ quy sẽ giảm chỉ số, cho đến khi chỉ số < 0 thì dừng.
*/

void inNguoc(int i) {
    if (i < 0) return;  // Điều kiện dừng khi đã in hết
    cout << ds[i].ma << " | Bắt đầu: " << ds[i].batDau
         << " | TG: " << ds[i].thoiGian << " phút\n";
    inNguoc(i - 1);  // Gọi đệ quy cho phần tử trước đó
}

// ------------------- Sinh tổ hợp 5 công việc -------------------
/*
 * Hàm sinhToHop sinh tất cả các tổ hợp gồm 5 công việc từ danh sách công việc ds.
 * Đây là một bài toán tổ hợp, dùng phương pháp đệ quy và quay lui (backtracking).
 *
 * Tham số:
 *  - vt: vị trí hiện tại trong danh sách ds đang xét
 *  - daChon: số lượng công việc đã chọn vào tổ hợp hiện tại
 *  - tam: vector tạm thời lưu mã công việc đang được chọn
 *  - count: đếm số lượng tổ hợp được tạo ra
 */
void sinhToHop(int vt, int daChon, vector<string>& tam, int& count) {
    // Trường hợp đã chọn đủ 5 công việc: in ra tổ hợp và return
    if (daChon == 5) {
        cout << ++count << ": ";
        for (string& ma : tam) cout << ma << " ";
        cout << "\n";
        return;
    }

    // Nếu đã đi hết danh sách mà chưa chọn đủ, kết thúc nhánh này
    if (vt >= ds.size()) return;

    // ----------- Nhánh 1: CHỌN công việc tại vị trí vt -----------
    tam.push_back(ds[vt].ma);                  // Thêm mã công việc vào tổ hợp tạm
    sinhToHop(vt + 1, daChon + 1, tam, count); // Gọi đệ quy tiếp theo với số lượng đã chọn tăng lên
    tam.pop_back();                            // Backtrack: loại bỏ công việc vừa chọn để thử nhánh khác

    // ----------- Nhánh 2: KHÔNG chọn công việc tại vị trí vt -----------
    sinhToHop(vt + 1, daChon, tam, count);     // Gọi đệ quy tiếp theo mà không chọn công việc hiện tại
}



int main() {
    cout << "== Danh sach cong viec (nguoc) ==\n";
    inNguoc(ds.size() - 1);

    cout << "\n== Tat ca cach chon 5 cong viec ==\n";
    vector<string> tam;
    int count = 0;
    sinhToHop(0, 0, tam, count);
    cout << "=> Tong cong: " << count << " phuong an\n";

    return 0;
}
