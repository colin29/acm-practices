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


int DP[3601];

vector<int> B;
void RAWR(int t){
	for(int i=0; i<B.size(); i++)
	if(B[i]>0){
			int count = DP[t] +1;
			int a = t + B[i];
			if(a>3600) a = 3600;
			if(count < DP[a]){
				DP[a]= count;
				RAWR(a);
			}
		}else{
			int count = DP[t] +1;
			int a = t + B[i];
			if(a<0) a = 0;
			if(count < DP[a]){
				DP[a]= count;
				RAWR(a);
			}
		}
}

int main(){
int t;
cin >> t;
while(t--){
	memset(DP, 999999, sizeof DP);
	int n, goal;
	cin >> n >> goal;
	B.clear();
	for(int i=0; i<n; i++){
		int a;
		cin >> a;
		B.push_back(a);
	}
	sort(B.rbegin(), B.rend());
	DP[0]=0;
	// for(int i=0; i<n; i++){
	// 	if(B[i]>0){
	// 	for(int j=0; j<=3600; j++){
			
	// 		int count = DP[j] +1;
	// 		int a = j + B[i];
	// 		if(a>3600) a = 3600;
	// 		DP[a] = min(count, DP[a]);
	// 		// cout << "set DP" << a << " to " << min(count, DP[a]) << endl;
	// 	}
	// 	}else{
	// 		for(int j=3600; j>=0; j--){
	// 		int count = DP[j] +1;
	// 		int a = j + B[i];
	// 		if(a<0) a = 0;
	// 		DP[a] = min(count, DP[a]);
	// 		}
	// 	}
	// }
	RAWR(0);

	int a = goal;
	while(DP[a] > 10000){
		a+=1;
	}
	cout << DP[a] << " " << a - goal << endl;
}


}