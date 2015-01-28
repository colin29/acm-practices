#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long int ll;

int main(){

ll n, a, d=0, total=0;
while(cin>>n && n){
	d=0; total =0;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		d+=a;
		total+=abs(d);
		//cout << "difference: " << d <<endl;
	}
	cout<< total<<endl;
}

}