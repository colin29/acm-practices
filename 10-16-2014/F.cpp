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

int main(){
int t;
cin >> t;
while(t--){
	ll a, b, c;
	cin >> a >> b>> c;
	while(b%2==0){
		b/=2;
		a-=1;
	}
	cout << a << endl;
}

}