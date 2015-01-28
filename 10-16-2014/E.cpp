#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstring>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;
int P[1000000];
int main(){
int t;
cin >> t;
while(t--){
	memset(P, 0, sizeof P);
int n;
cin >> n;
for(int i=0; i<n; i++){
	cin>>P[i];
}
int loc=0, max = 0, start =0, sum =0;
for(int i=0; i<n;i++){
	sum+=P[i]; //going to use this later;
	loc+=P[i];
	if(loc>max) max=loc;
	if(loc<0){
		loc=0;
	} 
}

// -1 6 -6 0 0 0 0 3.... well this still fails.
//Think I have it.
//anyways the key insight is that any  path that ends up looping around can be represented as the sum - a negative chunk (non-looping).
//finding the most negative chunk gives you the best looping path. take the max of best non-looping and looping path.

	int min =0;
	loc=0;
	for(int i=0; i<n;i++){
		loc+=P[i];
		if(loc<min) min=loc;
		if(loc>0){
			loc=0; //reset loc, mark start;
		}
	}
	max = std::max(max, sum - min); 

cout << max << endl;


}


}