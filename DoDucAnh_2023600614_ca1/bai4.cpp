#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct CB đại diện cho 1 chuyến bay gồm mã chuyến (id), giá vé (gia) và số ghế (ghe)
struct CB {
    string id;
    int gia;
    int ghe;
};

// Danh sách 7 chuyến bay mẫu
vector<CB> ds = {
    {"VN101", 500000, 120},
    {"VN102", 850000, 150},
    {"VN103", 700000, 100},
    {"VN104", 900000, 180},
    {"VN105", 600000, 90},
    {"VN106", 750000, 110},
    {"VN107", 720000, 130},
    {"VN108", 650000, 105}
};


/* 
 * Hàm đệ quy: inGiaLon700k
 * Mục đích: In ra tất cả các chuyến bay có giá vé > 700000
 * Tham số:
 *    - ds: danh sách các chuyến bay
 *    - i: chỉ số hiện tại đang xét trong danh sách
 * Cách hoạt động:
 *    - Nếu đã vượt quá cuối danh sách, kết thúc hàm
 *    - Nếu giá vé của chuyến bay tại vị trí i > 700000 thì in ra
 *    - Gọi đệ quy với chỉ số i + 1 để tiếp tục xét phần tử tiếp theo
 */
// Nếu không có chuyến nào, in thông báo
void inGiaLon700k(const vector<CB>& ds, int i, int dem) {
    if (i >= ds.size()) {
        if (dem == 0)
            cout << "=> Khong co chuyen bay nao co gia > 700000\n";
        return;
    }

    if (ds[i].gia > 700000) {
        cout << ds[i].id << " - " << ds[i].gia << " VND - " << ds[i].ghe << " ghe\n";
        dem++;
    }

    inGiaLon700k(ds, i + 1, dem);
}


/*
 * Hàm chia để trị: minGia
 * Mục đích: Tìm chuyến bay có giá vé thấp nhất trong đoạn từ chỉ số l đến r
 * Tham số:
 *    - ds: danh sách chuyến bay
 *    - l: chỉ số bắt đầu đoạn cần xét
 *    - r: chỉ số kết thúc đoạn cần xét
 * Cách hoạt động:
 *    - Nếu chỉ còn 1 phần tử (l == r) thì trả về phần tử đó
 *    - Chia đoạn [l, r] thành 2 nửa:
 *        + Gọi đệ quy tìm giá nhỏ nhất ở nửa trái
 *        + Gọi đệ quy tìm giá nhỏ nhất ở nửa phải
 *    - Trả về chuyến bay có giá nhỏ hơn trong 2 nửa
 */
CB minGia(const vector<CB>& ds, int l, int r) {
    if (l == r) return ds[l];
    int mid = (l + r) / 2;
    CB a = minGia(ds, l, mid);
    CB b = minGia(ds, mid + 1, r);
    return (a.gia < b.gia) ? a : b;
}

/*
 * Hàm quay lui: quayLui
 * Mục đích: Sinh tất cả các tổ hợp gồm đúng 4 chuyến bay khác nhau từ danh sách ds
 * Tham số:
 *    - vt: vị trí hiện tại trong danh sách đang xét
 *    - daChon: số lượng chuyến bay đã chọn tính đến thời điểm hiện tại
 *    - current: vector lưu tổ hợp chuyến bay đang được xây dựng
 *    - count: đếm số tổ hợp đã in ra
 * Cách hoạt động:
 *    - Nếu đã chọn đủ 4 chuyến bay thì in ra tổ hợp và kết thúc nhánh này
 *    - Nếu đã duyệt hết danh sách mà chưa chọn đủ 4 thì dừng
 *    - Nhánh 1: chọn chuyến bay tại vị trí `vt`, rồi gọi tiếp với daChon + 1
 *    - Nhánh 2: không chọn chuyến bay tại `vt`, gọi tiếp mà không tăng daChon
 * => Quá trình tạo tổ hợp chính là quá trình quay lui (backtracking) theo 2 lựa chọn tại mỗi bước: chọn hoặc không chọn
 */
void quayLui(int vt, int daChon, vector<string>& current, int& count) {
    if (daChon == 4) {
        cout << ++count << ": ";
        for (string& id : current)
            cout << id << " ";
        cout << "\n";
        return;
    }

    if (vt >= ds.size()) return;

    // Chọn chuyến bay tại vị trí hiện tại
    current.push_back(ds[vt].id);
    quayLui(vt + 1, daChon + 1, current, count);

    // Không chọn chuyến bay tại vị trí hiện tại
    current.pop_back();
    quayLui(vt + 1, daChon, current, count);
}


int main() {
    cout << "1. Cac chuyen co gia > 700000:\n";
    inGiaLon700k(ds, 0, 0);

    cout << "\n2. Chuyen co gia thap nhat:\n";
    CB minCB = minGia(ds, 0, ds.size() - 1);
    cout << minCB.id << " - " << minCB.gia << " VND - " << minCB.ghe << " ghe\n";

    cout << "\n3. Cac cach chon 4 chuyen bay:\n";
    vector<string> current;
    int count = 0;
    quayLui(0, 0, current, count);
    cout << "\n=> Tong so cach chon: " << count << "\n";

    return 0;
}

/*

vector<CB> ds1 = {
    {"VN101", 500000, 120},
    {"VN102", 850000, 150},
    {"VN103", 700000, 100},
    {"VN104", 900000, 180},
    {"VN105", 600000, 90},
    {"VN106", 750000, 110},
    {"VN107", 720000, 130},
    {"VN108", 650000, 105}
};

vector<CB> ds2 = {
    {"BL201", 500000, 100},
    {"BL202", 650000, 95},
    {"BL203", 700000, 110},
    {"BL204", 550000, 105},
    {"BL205", 690000, 115},
    {"BL206", 480000, 120},
    {"BL207", 600000, 90}
};

vector<CB> ds3 = {
    {"QH301", 400000, 100},
    {"QH302", 720000, 105},
    {"QH303", 680000, 130},
    {"QH304", 810000, 140},
    {"QH305", 750000, 120},
    {"QH306", 500000, 90},
    {"QH307", 950000, 150},
    {"QH308", 700000, 100},
    {"QH309", 620000, 110},
    {"QH310", 880000, 135}
};


*/

