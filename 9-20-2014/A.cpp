#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>

const long double EPS = 1e-9;

using namespace std;

int main(){
int n;
while(cin>>n && n){
	string s;
	vector<int> v(3, 0);
	for(int i=0; i<n;i++){
		cin >>s;
		if(s=="Cheddar"){
			v[0]+=1;
		}else if (s=="Gouda"){
			v[1]+=1;
		}else{
			v[2]+=1;
		}
	}
	sort(v.begin(), v.end());
	int max=0;
	for(int i=0; i<v.size(); i++){
	int a = v[i]*(v.size()-i);
	if(a>max)
		max=a;
	}
	cout << max << endl;
}

}