#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>

const long double EPS = 1e-9;

using namespace std;

int main(){

int t;
cin >> t;

vector<int> H(5);
vector<int> E(5);
vector<int> D(5);
while(t--){
	double edps =0;
	double dps = 0;
	for (int i = 0; i < 5; ++i) {
		cin >>H[i];
	}
	for (int i = 0; i < 5; ++i) {
		cin >>E[i];
		edps += E[i];
	}
	for (int i = 0; i < 5; ++i) {
		cin >>D[i];
		dps+=D[i];
	}

	vector<int>v {0, 1, 2, 3, 4};
	// for (int i = 0; i < 5; ++i) {
	// 	v[i] = i;
	// }

	double l;
	double min = 1e100;
	do{	
		double cedps = edps;
		l=0;
		for (int i = 0; i < 5; ++i)
		{
			l+= H[v[i]]*cedps/dps;
			//cout << H[v[i]]*cedps << " " << H[v[i]]*cedps/dps <<endl;
			cedps -= E[v[i]];

		}
		//cout << l << endl;
		if(l<min)
			min=l;
	}while(next_permutation(v.begin(), v.end()));
	cout << setprecision(5) << fixed << min << endl;
}

}