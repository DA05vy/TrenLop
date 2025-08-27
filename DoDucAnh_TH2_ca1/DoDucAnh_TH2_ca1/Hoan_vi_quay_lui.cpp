#include <iostream>
#include <vector>
using namespace std;


vector<int> x;
vector<bool> dd;

void inkq( int n ){
  for ( int i = 1; i <= n; i++ ){
    cout << x[i] << " ";
  }
  cout << endl;
}

void hoanvi( int k, int n ){
  for ( int i = 1; i <= n; i++ ){
    if ( dd[i] == 0 ){
      x[k] = i;

      if ( k == n ){
        inkq(n);
      } else {
        dd[i] = 1;
        hoanvi(k+1, n );
        dd[i] = 0;
      }

    }
  }
}

int main(){
  int n;cin >> n;
  dd.assign( n + 1, false);
  x.resize(n+1);
  hoanvi(1,n);
  return 0;
}
