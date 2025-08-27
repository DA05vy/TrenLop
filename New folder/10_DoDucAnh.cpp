#include <iostream>
#include <vector>
using namespace std;


int sumOdd(const vector<int>& arr, int index, int size) {
    if (index == size) {
        return 0;
    }

    int current_num = arr[index];
    if (current_num % 2 != 0) {
        return current_num + sumOdd(arr, index + 1, size);
    }
    else {
        return sumOdd(arr, index + 1, size);
    }
}

int main() {
    vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Tong cac so le trong day 1 la: "
         << sumOdd(n, 0, n.size()) << endl;

    return 0;
}
