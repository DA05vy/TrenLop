#include <iostream>
#include <vector>
#include <algorithm> // For std::sort
#include <iomanip>   // For std::fixed, std::setprecision

using namespace std;

// Struct đại diện cho một kiện hàng
struct KienHang {
    int id;           // ID kiện hàng
    double khoi_luong; // Khối lượng
    double kich_thuoc; // Kích thước
    double ti_le_hieu_qua; // Khối lượng / Kích thước

    // Constructor để khởi tạo và tính tỉ lệ hiệu quả
    KienHang(int i, double kl, double kt) : id(i), khoi_luong(kl), kich_thuoc(kt) {
        ti_le_hieu_qua = (kt > 0) ? (kl / kt) : 0;
    }
};

// Hàm so sánh để sắp xếp kiện hàng theo tỉ lệ hiệu quả GIẢM DẦN
bool soSanhKienHang(const KienHang& a, const KienHang& b) {
    return a.ti_le_hieu_qua > b.ti_le_hieu_qua;
}

// Hàm chính giải quyết bài toán John xếp hàng
double xepHangThamLam(double truckCapacity, vector<KienHang>& packages, vector<KienHang>& chosenPackages) {
    // 1. Sắp xếp kiện hàng theo tỉ lệ hiệu quả GIẢM DẦN (Tham Lam)
    // Đây là BƯỚC QUAN TRỌNG NHẤT và là NỀN TẢNG của chiến lược tham lam này.
    // Hàm 'sort' từ thư viện <algorithm> sẽ sắp xếp vector 'packages'.
    // Hàm 'soSanhKienHang' (đã định nghĩa ở ngoài hàm này) được dùng làm tiêu chí sắp xếp.
    // Nó đảm bảo rằng các kiện hàng có 'ti_le_hieu_qua' (khối lượng/kích thước) cao nhất
    // sẽ nằm ở đầu danh sách, được xem xét đầu tiên.
    sort(packages.begin(), packages.end(), soSanhKienHang);

    // 2. Khởi tạo các biến theo dõi
    // totalMassLoaded: Biến này sẽ tích lũy tổng khối lượng của các kiện hàng đã được John xếp lên xe.
    double totalMassLoaded = 0.0;
    // currentTruckSpace: Biến này theo dõi không gian còn lại trong thùng xe.
    // Ban đầu, nó bằng với 'truckCapacity' tối đa của thùng xe.
    double currentTruckSpace = truckCapacity;

    // 3. Duyệt và chọn kiện hàng (Theo thứ tự đã sắp xếp)
    // Vòng lặp 'for' này sẽ duyệt qua TỪNG kiện hàng trong vector 'packages'
    // mà hiện tại đã được sắp xếp theo thứ tự ưu tiên tham lam (hiệu quả giảm dần).
    for (const auto& kien : packages) {
        // Kiểm tra điều kiện dừng: Nếu thùng xe đã đầy (không còn chỗ trống)
        // hoặc chỗ trống là số âm (do tính toán), thì không thể xếp thêm gì nữa.
        // Ngay lập tức thoát khỏi vòng lặp.
        if (currentTruckSpace <= 0) {
            break;
        }

        // Kiểm tra điều kiện lựa chọn:
        // Nếu kích thước của kiện hàng hiện tại ('kien.kich_thuoc')
        // nhỏ hơn hoặc bằng không gian còn lại trong thùng xe ('currentTruckSpace').
        // Điều này có nghĩa là kiện hàng có thể VỪA ĐẶT VÀO thùng xe.
        if (kien.kich_thuoc <= currentTruckSpace) {
            // --- Hành động khi kiện hàng VỪA ---
            chosenPackages.push_back(kien);          // Thêm kiện hàng này vào danh sách các kiện đã chọn.
                                                    // (Đây là kết quả mà bạn muốn hiển thị cho người dùng).
            totalMassLoaded += kien.khoi_luong;      // Cộng khối lượng của kiện hàng này vào tổng khối lượng đã xếp.
            currentTruckSpace -= kien.kich_thuoc;    // Giảm không gian còn lại của thùng xe bằng kích thước của kiện hàng vừa xếp.
        }
        // else { ... }
        // Nếu kiện hàng KHÔNG VỪA, chúng ta KHÔNG LÀM GÌ CẢ với kiện hàng này.
        // Đây là bản chất của bài toán 0/1 Knapsack (lấy toàn bộ hoặc không lấy gì).
        // Chúng ta đơn giản là bỏ qua nó và chuyển sang kiện hàng tiếp theo (có hiệu quả thấp hơn).
    }

    // 4. Trả về kết quả
    // Sau khi vòng lặp kết thúc (do hết kiện hàng hoặc thùng xe đầy),
    // hàm sẽ trả về tổng khối lượng lớn nhất mà John đã xếp được lên xe.
    return totalMassLoaded;
}

int main() {
    double kich_thuoc_thung_xe = 20.0;

    // Danh sách kiện hàng: {ID, Khối lượng (kg), Kích thước (m3)}
    vector<KienHang> danh_sach_kien_hang = {
        {1, 10, 5},
        {2, 12, 4},
        {3, 8, 3},
        {4, 15, 6},
        {5, 7, 2}
    };

    vector<KienHang> kien_hang_da_chon; // Kết quả

    cout << "--- Bai toan Xep Hang Len Xe Tai (John) ---" << endl;
    cout << "Kich thuoc thung xe: " << fixed << setprecision(2) << kich_thuoc_thung_xe << " m3" << endl;

    double maxMass = xepHangThamLam(kich_thuoc_thung_xe, danh_sach_kien_hang, kien_hang_da_chon);

    cout << "Tong khoi luong lon nhat xep duoc: " << fixed << setprecision(2) << maxMass << " kg" << endl;
    cout << "Cac kien hang da duoc xep len xe:" << endl;
    if (kien_hang_da_chon.empty()) {
        cout << "  Khong co kien hang nao duoc xep." << endl;
    } else {
        for (const auto& kien : kien_hang_da_chon) {
            cout << "  - ID: " << kien.id
                 << " (KL: " << fixed << setprecision(2) << kien.khoi_luong
                 << "kg, KT: " << fixed << setprecision(2) << kien.kich_thuoc << "m3)" << endl;
        }
    }

    return 0;
}