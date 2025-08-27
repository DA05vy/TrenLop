#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// C: Vector chứa tải trọng của các xe tải (phải được sắp xếp GIẢM DẦN trước khi gọi)
// m: Số lượng loại xe trong C (C.size())
// n_hang_can_cho: Tổng lượng hàng cần vận chuyển. Dùng tham chiếu '&' để hàm main biết nếu còn hàng thừa.
// S: Vector để lưu trữ số lượng xe đã được chọn của mỗi loại (kết quả đầu ra)
//
// Trả về true nếu tất cả hàng được vận chuyển hết,
// Trả về false nếu không thể vận chuyển hết hàng bằng các xe có sẵn theo chiến lược này.
bool layxe ( vector<int> &C, int m, int &n_hang_can_cho, vector<int> &S ){ // Đã thêm '&' vào n_hang_can_cho
    // Khởi tạo số lượng xe cho mỗi loại là 0
    // Đảm bảo S có kích thước đủ (bằng số loại xe m) và tất cả phần tử là 0
    S.assign(m, 0);

    // Sử dụng biến cục bộ để tính toán, sau đó gán lại cho n_hang_can_cho khi kết thúc.
    // Điều này giúp tránh thay đổi n_hang_can_cho gốc trong vòng lặp.
    long long current_n = n_hang_can_cho; 

    int i = 0;
    while (current_n > 0 && i < m) { // Duyệt qua các loại xe
        int tai_trong_xe = C[i]; // Tải trọng của loại xe hiện tại

        if (tai_trong_xe <= 0) { // Tránh chia cho 0 hoặc tải trọng không hợp lệ
            ++i;
            continue;
        }

        S[i] = current_n / tai_trong_xe; // Số lượng xe loại C[i] được dùng
        current_n = current_n % tai_trong_xe; // Cập nhật số hàng còn lại
        ++i;
    }

    // Cập nhật lại giá trị n_hang_can_cho gốc để hàm main có thể biết lượng hàng còn lại
    n_hang_can_cho = current_n; // Gán lại giá trị cuối cùng của current_n vào n_hang_can_cho gốc

    if (n_hang_can_cho > 0) { // Nếu còn hàng không thể chở hết
        return false; // Trả về false
    }
    return true; // Trả về true nếu đã chở hết hàng
}

int main(){
    vector<int> C = { 100,40,21,53,34,65,80,10 };
    // Sắp xếp tải trọng xe giảm dần để áp dụng chiến lược tham lam
    sort(C.rbegin(), C.rend()); 
    int m = C.size(); // Số lượng loại xe
    int n = 1024;     // Tổng lượng hàng cần vận chuyển
    // S vector phải có kích thước bằng số loại xe (m) để chứa kết quả tương ứng
    vector<int> S(m); // Khởi tạo S với kích thước m


    int initial_n_value = n; // Biến này sẽ giữ giá trị n ban đầu (1024)

    // Gọi hàm layxe. n được truyền bằng tham chiếu nên sẽ cập nhật lượng hàng còn lại (nếu có).
    if (layxe(C, m, n, S)) { // n ở đây là tham chiếu và sẽ thay đổi sau hàm
        cout << "Hàng đã được vận chuyển hết!" << endl;
        cout << "Số lượng xe của từng loại được sử dụng:" << endl;
        for (int i = 0; i < m; ++i) {
            if (S[i] > 0) {
                cout << "  Loại xe " << C[i] << " tấn: " << S[i] << " chiếc" << endl;
            }
        }
    } else {
        // --- PHẦN ĐÃ SỬA: Dùng initial_n_value cho thông báo tổng ban đầu ---
        cout << "KHÔNG THỂ vận chuyển hết " << initial_n_value << " tấn hàng với các xe hiện có bằng chiến lược tham lam này." << endl;
        cout << "Còn thiếu: " << n << " tấn hàng." << endl; // n giờ là lượng hàng còn thừa sau khi hàm layxe chạy
        // --- KẾT THÚC PHẦN SỬA ---
        cout << "Các xe đã được sử dụng (theo khả năng):" << endl;
        for (int i = 0; i < m; ++i) {
            if (S[i] > 0) {
                cout << "  Loại xe " << C[i] << " tấn: " << S[i] << " chiếc" << endl;
            }
        }
    }
    return 0;
}