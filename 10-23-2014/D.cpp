#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>

typedef long long int ll;
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;
const long double EPS = 1e-9;

using namespace std;

int main(){
int n,p;
cin >> n >> p;
int min=1e8;
int max=0;

VI C;
for(int i=0; i<n; i++){
	int d;
	cin >> d;
	C.push_back(d);
}
sort(C.begin(), C.end());
for(int i=0; i<n; i++){
	max=std::max(max, p*(i+1)-C[i]);
}
cout << max+C[0] << endl;


}