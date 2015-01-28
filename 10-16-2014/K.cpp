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
int n, g;
cin >> n >> g;
int a,b;
a=(n+1)/3;
b=n/3;
cout << ((g>b && g<= n-a)? "YES": "NO") << endl;

return 0;
}