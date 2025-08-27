#include <iostream>
#include <vector>
using namespace std;

int n, x[100];

void inkq(){
  for ( int i = 1; i <= n; i++ ){
    cout << x[i];
  }
  cout << endl;
}

void nhiphan( int k, int n ){
  for ( int i = 0; i <= 1; i++ ){
    x[k] = i;
    if ( k == n ){
      inkq();
    } else {
      nhiphan( k+1, n);
    }
  }
}

int main(){
  cin >> n;
  nhiphan(1,n);
  return 0;
}
