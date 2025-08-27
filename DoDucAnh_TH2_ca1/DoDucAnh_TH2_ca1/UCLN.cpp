#include<iostream>
using namespace std;

int ucln( int a, int b ){
    if ( a % b == 0 ) return b;
    else return ucln(b, a%b);
}

int ucln_khu( int a, int b ){
    int r = a%b;
    while( r != 0 ){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

int main(){
    int a,b;
    cin >> a >> b;
    cout << "Tim ucln bang de quy: " << ucln(a,b) << endl;
    cout << "Tim ucln bang khu de quy: " << ucln_khu(a,b) << endl;
    return 0;
}
