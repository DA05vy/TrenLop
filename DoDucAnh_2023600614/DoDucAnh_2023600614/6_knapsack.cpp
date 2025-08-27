#include <iostream>  
#include <vector>   
#include <algorithm> 
#include <iomanip>   
using namespace std;

// Hàm giải quyết bài toán Ba Lô cho cô trộm
// Sử dụng chiến lược tham lam: ưu tiên chọn gói hàng có khối lượng TĂNG DẦN (nhẹ nhất trước).
//
// Tham số:
//   m_arr[]: Mảng chứa khối lượng (mass) của các gói hàng. Đây là dữ liệu đầu vào.
//   s_arr[]: Mảng chứa kích thước (size) của các gói hàng. Đây là dữ liệu đầu vào.
//   n:       Số lượng gói hàng (số phần tử trong m_arr và s_arr).
//   backpack_capacity: Kích thước tối đa mà ba lô có thể chứa.
//   total_mass_taken:  Biến tham chiếu, sẽ lưu tổng khối lượng các gói hàng ĐÃ ĐƯỢC CHỌN.
//   total_size_taken:  Biến tham chiếu, sẽ lưu tổng kích thước các gói hàng ĐÃ ĐƯỢC CHỌN.
//   is_chosen[]: Mảng boolean, đánh dấu true nếu gói hàng tại vị trí đó được chọn, false nếu không.
void backpackGreedyForThief(const double m_arr[], const double s_arr[], int n, double backpack_capacity,
                            double& total_mass_taken, double& total_size_taken, bool is_chosen[])
{
    // current_masses[]: Mảng tạm thời để lưu khối lượng của các gói hàng.
    // Chúng ta sẽ sắp xếp mảng này để tìm thứ tự ưu tiên các gói hàng.
    double current_masses[n];

    // pos[]: Mảng lưu VỊ TRÍ GỐC (chỉ số ban đầu) của các gói hàng.
    // Khi chúng ta sắp xếp current_masses, chúng ta cũng phải hoán đổi các phần tử tương ứng trong pos
    // để biết gói hàng ở vị trí 'i' sau khi sắp xếp tương ứng với gói hàng nào trong mảng gốc m_arr/s_arr.
    int pos[n];

    // Khởi tạo các mảng:
    // - pos[i] = i: Mỗi gói hàng ban đầu có vị trí bằng chính chỉ số của nó.
    // - is_chosen[i] = false: Ban đầu, chưa có gói hàng nào được chọn.
    // - current_masses[i] = m_arr[i]: Sao chép khối lượng từ mảng gốc để có thể sắp xếp.
    for(int i = 0; i < n; i++)
    {
        pos[i] = i;
        is_chosen[i] = false;
        current_masses[i] = m_arr[i];
    }

    // --- BƯỚC 1: Sắp xếp các gói hàng theo khối lượng TĂNG DẦN (Tham Lam) ---
    // Đây là phần cốt lõi của chiến lược tham lam cho bài toán này.
    // Vòng lặp này thực hiện sắp xếp kiểu "Bubble Sort" trên mảng current_masses.
    // Đồng thời, nó hoán đổi các phần tử trong mảng pos để giữ nguyên ánh xạ tới vị trí gốc.
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // So sánh khối lượng: Nếu khối lượng ở vị trí 'i' LỚN HƠN khối lượng ở vị trí 'j'
            // thì cần hoán đổi chúng để đảm bảo thứ tự TĂNG DẦN.
            if (current_masses[i] > current_masses[j])
            {
                swap(current_masses[i], current_masses[j]); // Hoán đổi khối lượng
                swap(pos[i], pos[j]);                       // Hoán đổi vị trí gốc tương ứng
            }
        }
    }

    // Khởi tạo tổng khối lượng và tổng kích thước đã lấy về 0.
    total_mass_taken = 0.0;
    total_size_taken = 0.0;

    // --- BƯỚC 2: Duyệt qua các gói hàng đã sắp xếp và lựa chọn ---
    // Các gói hàng hiện đang được duyệt theo thứ tự khối lượng TĂNG DẦN.
    for (int i = 0; i < n; i++)
    {
        // Lấy chỉ số (ID) gốc của gói hàng hiện tại sau khi đã sắp xếp.
        // Ví dụ: nếu pos[0] là 4, nghĩa là gói hàng nhẹ nhất nằm ở chỉ số 4 trong mảng gốc.
        int original_idx = pos[i];

        // Kiểm tra điều kiện: Nếu thêm gói hàng này vào ba lô mà TỔNG KÍCH THƯỚC KHÔNG VƯỢT QUÁ
        // sức chứa của ba lô.
        if (total_size_taken + s_arr[original_idx] <= backpack_capacity)
        {
            // Nếu gói hàng vừa:
            total_mass_taken += m_arr[original_idx];      // Cộng khối lượng của gói hàng vào tổng.
            total_size_taken += s_arr[original_idx];      // Cộng kích thước của gói hàng vào tổng.
            is_chosen[original_idx] = true;                // Đánh dấu gói hàng này là đã chọn (ở vị trí gốc của nó).
        }
        else // Nếu gói hàng hiện tại không vừa với không gian còn lại của ba lô
        {
            // Theo chiến lược tham lam, khi một gói hàng không vừa, chúng ta dừng lại.
            // (Vì các gói tiếp theo trong danh sách đều NẶNG HƠN hoặc có cùng khối lượng
            //  nhưng kích thước lớn hơn, nên chúng ta không xét nữa.)
            break;
        }
    }
}

int main()
{
    // Dữ liệu đầu vào cho Bài 6:
    // Mảng 'masses' (khối lượng) và 'sizes' (kích thước) phải tương ứng với nhau theo chỉ số.
    double masses[] = {5.0, 3.0, 8.0, 7.0, 2.0}; // Khối lượng (kg) của các gói hàng
    double sizes[]  = {3.0, 2.0, 4.0, 5.0, 1.0}; // Kích thước (m3) của các gói hàng
    int n = 5; // Có 5 gói hàng (từ 1 đến 5)

    // Mảng boolean để lưu kết quả: gói nào được chọn (true) gói nào không (false).
    // Kích thước mảng này phải bằng 'n'.
    bool selected_items[n];

    // Kích thước tối đa của ba lô cô trộm.
    double backpack_k = 10.0; // Đơn vị: m3

    // Các biến này sẽ lưu kết quả cuối cùng (tổng khối lượng và tổng kích thước đã chọn).
    // Chúng được truyền vào hàm dưới dạng tham chiếu để hàm có thể cập nhật giá trị của chúng.
    double total_mass_selected, total_size_selected;


    // Gọi hàm giải bài toán tham lam.
    // Hàm này sẽ tính toán và cập nhật giá trị của total_mass_selected, total_size_selected, và selected_items.
    backpackGreedyForThief(masses, sizes, n, backpack_k, total_mass_selected, total_size_selected, selected_items);

    // In kết quả cuối cùng
    cout << "Tong khoi luong cac goi hang da chon: "
         << fixed << setprecision(2) << total_mass_selected << " kg" << endl; // Định dạng hiển thị 2 chữ số thập phân
    cout << "Tong kich thuoc cac goi hang da chon: "
         << fixed << setprecision(2) << total_size_selected << " m3" << endl; // Định dạng hiển thị 2 chữ số thập phân
    cout << "Cac goi hang da duoc chon (1 = chon, 0 = khong chon):" << endl;
    for(int i = 0; i < n; i++) {
        cout << selected_items[i] << " "; // In 1 nếu chọn, 0 nếu không
    }
    cout << endl;

    return 0;
}