#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

ll fib[1000];
int main(){
int t;
cin >> t;
fib[0] = 1;
fib[1] = 1;
for(int i=1; fib[i-1]<10e9; i++){
	fib[i+1] = fib[i] + fib[i-1];
	cout << fib[i+1] << endl;
}
while(t--){
	int n;
	cin >> n;
	int ans;
	int a, b;
	for(int i=1; fib[i]<=n; i++){
		if((n%fib[i])%fib[i-1] == 0)){
			int d = n/(fib[i+1]);
			a=n/fib[i];
			b=(n%fib[i]/fib[i-1]);
			int g = gcd(fib[i], fib[i-1]);
			int da = a/g;
			int db = b/g;

		}
	}
}

}