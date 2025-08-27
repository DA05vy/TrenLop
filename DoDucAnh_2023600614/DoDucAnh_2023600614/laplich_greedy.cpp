#include <bits/stdc++.h>
using namespace std;

// Sắp xếp các cặp (start_time, finish_time) dựa trên finish_time (giá trị thứ hai)
bool comparePairsByFinishTime( pair<double, double>& a, pair<double, double>& b) {
    return a.second < b.second;
}

// Hàm laplich nhận vào một vector các cặp (start_time, finish_time)
void laplich(vector<pair<double, double>>& activities, vector<pair<double, double>> &scheduled_activities) {
    // Bước 1: Sắp xếp vector các cặp theo finish_time 
    // Sắp xếp các cặp (start_time, finish_time) dựa trên finish_time 
    sort(activities.begin(), activities.end(), comparePairsByFinishTime);

    if (!activities.empty()) {
        // Chọn công việc đầu tiên (có thời gian kết thúc sớm nhất sau khi sắp xếp)
        scheduled_activities.push_back(activities[0]);
        double last_finish_time = activities[0].second; // Lấy finish_time (giá trị thứ hai)

        // Duyệt qua các công việc còn lại
        for (size_t i = 1; i < activities.size(); ++i) {
            // Kiểm tra xem thời gian bắt đầu của công việc hiện tại (giá trị thứ nhất)
            // có lớn hơn hoặc bằng thời gian kết thúc của công việc đã chọn cuối cùng không
            if (activities[i].first >= last_finish_time) {
                scheduled_activities.push_back(activities[i]); // Thêm công việc này vào lịch
                last_finish_time = activities[i].second;       // Cập nhật thời gian kết thúc mới
            }
        }
    }
}

int main() {
    // Khai báo và khởi tạo vector các cặp (start_time, finish_time) ngay từ đầu
    vector<pair<double, double>> initial_activities = {
        {1.0, 2.0},
        {3.0, 4.0},
        {0.0, 6.0},
        {5.0, 6.0},
        {8.0, 9.0},
        {5.0, 9.0}
    };

    cout << "Cac cong viec ban dau (Start, Finish):" << endl;
    for ( auto activity : initial_activities) {
        cout << "(" << activity.first << ", " << activity.second << ")" << endl;
    }
    
    // Tạo một bản sao để truyền vào hàm laplich, tránh làm thay đổi initial_activities
    vector<pair<double, double>> scheduled_activities; // Vector lưu trữ các công việc được lập lịch

    laplich(initial_activities, scheduled_activities);
    
    cout << "\nCac cong viec duoc lap lich (theo thu tu ket thuc - Start, Finish):" << endl;
    if (scheduled_activities.empty()) {
        cout << "Khong co cong viec nao duoc lap lich." << endl;
    } else {
        for ( auto activity : scheduled_activities) {
            cout << "(" << activity.first << ", " << activity.second << ") ";
        }
        cout << endl;
    }
    return 0;
}