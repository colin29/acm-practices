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
int n;
cin >> n;
vector<int> P;
vector<int> Q;
for (int i=0; i<n; i++){
	int a;
	cin >> a;
	P.push_back(a);
}
for (int i=0; i<n; i++){
	int a;
	cin >> a;
	Q.push_back(a);
}
sort(P.begin(), P.end());
sort(Q.begin(), Q.end());
vector<int> dif1(n, 0);
vector<int> dif2(2*n, 0);

for(int i=0; i<n; i++){
	dif1[i]=(P[(i+1)%(n)]-P[i]);
	if(i==n-1){
		dif1[i]= (P[(i+1)%(n)]-P[i%(n)])+360000;
	}
	//cout << dif1[i] << endl;
}

for(int i=0; i<n; i++){
	dif2[i]=(Q[(i+1)%(n)]-Q[i]);
	if(i==n-1){
		dif2[i]= (Q[(i+1)%(n)]-Q[i%(n)])+360000;
	}
}
for(int i=0; i<n; i++){
	dif2[i+n]=(Q[(i+1)%(n)]-Q[i]);
	if(i==n-1){
		dif2[i+n]= (Q[(i+1)%(n)]-Q[i%(n)])+360000;
	}
}
int i=0; int j=-1;
int b[n+1];
b[i]=j;
while(i<n){
	while(j>=0 && dif1[i]!=dif1[j])
	{
		 j=b[j];
	}
	i++; j++;
	b[i]=j;
	
}

bool isGood = false;
i=0; j=0;
while(i<2*n){
	while(j>=0 && dif2[i] != dif1[j]) j=b[j];
	i++; j++;
	if(j==n)
	{
		isGood = true;
	}
}


cout << (isGood? "possible": "impossible") << endl;



}