#include<bits/stdc++.h>
using namespace std;
void chuyen( int n, string a, string b, string c){
    if ( n == 1 ){
        cout << "chuyen tu coc " << a << " sang coc " << c << endl;
    } else {
        chuyen(n-1,a,c,b);
        chuyen(1,a,b,c);
        chuyen(n-1,b,a,c);
    }
}

// Define the stack globally or pass it as a parameter
stack<tuple<int, string, string, string>> s;

void chuyen_khu(int n, string a, string b, string c) {
    s.push({n, a, b, c});
    while (!s.empty()) {
        tuple<int, string, string, string> state = s.top();
        s.pop();
        int n = get<0>(state);
        string a = get<1>(state);
        string b = get<2>(state);
        string c = get<3>(state);

        if (n == 1) {
            cout << "chuyen tu coc " << a << " sang coc " << c << endl;
        } else {
            s.push({n-1, b, a, c});
            s.push({1, a, b, c});
            s.push({n-1, a, c, b});
        }
    }
}



int main(){
    int n; cin >> n;
    chuyen(n,"A", "B", "C");
    cout << endl;

    chuyen_khu(n, "A", "B", "C");
    return 0;
}
