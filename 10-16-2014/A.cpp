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
ll P[100001];
ll cur =1;
ll temp;
for(int i=1; i<=100000; i++){
	if(i==1){
		P[i]=0; continue;
	}
	
	cur*=i;
	cur%=1000000007;
	temp = cur;
	temp -=1;
	if(temp==-1){
		temp+=1000000007;
	}
	P[i]=temp;
	//cout << temp << endl;
}
int t;
cin>> t;
for(int i=0; i<t; i++){
	int a;
	cin >> a;
	cout << P[a] << endl;
}

}