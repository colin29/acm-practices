#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <math.h>
#include <string.h>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

int main(){
	ll c, n;
	cin >> c >> n;
	ll p =0;
	ll isOk = true;

	for(int i=0; i<n; i++){
		ll in, out, stay;
		cin >> out >> in >> stay; 
		p = p-out;
		if(p<0)
			isOk=false;
		p+= in;
		if(p<c && stay !=0){
			isOk = false;
		}
		if(p>c)
			isOk = false;
	}

	if(p!=0)
		isOk = false;

	cout << (isOk?"possible": "impossible") << endl;
}