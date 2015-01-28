#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <stack>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

int main(){
ll n;
while(cin>>n && n){
	ll nn = n;
	int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	vector<int> p;
	p.assign(prime, prime+(sizeof prime)/sizeof(*prime));
	ll prod = 1;
	for (int i = 0; i < p.size(); ++i)
	{
		prod*=p[i];
	}

	vector<ll> coef;
	for(int i=p.size()-1; i>=0; i--){
		prod/=p[i];
		coef.insert(coef.begin(), n/prod);
		n%=prod;
	}
	bool flag = false;
	cout << nn << " = ";
	for(int i=0; i<coef.size(); i++){
		if(coef[i]!=0){
		cout << (flag? " + " : "");
		flag = true;
		cout<<coef[i];
			for(int j=0; j<i; j++){
				cout << "*" << p[j];
			}
		}
	}
	cout << endl;

}
}