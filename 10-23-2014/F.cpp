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
int n;
cin >> n;
string s;

getline(cin, s);
for (int i = 0; i < n; ++i)
{
	char c = cin.peek();
	if(c=='P'){
		cout << "skipped" << endl;
	}else{
		int a, b;
		cin >> a;
		cin.ignore(1);
		cin >> b;
		cout << a+b << endl;
	}
	getline(cin, s);
}
cout << endl;

}