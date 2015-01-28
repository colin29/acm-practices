#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool DP [10001][101]; //bounds are the max sum
int num[10000];

bool f(int n, int k){

//memset(DP, 0, sizeof DP);
for(int i=0; i<=n; i++){ 
	for(int j=0; j<=k; j++){ 
		if(j==0){
			DP[i][j]=true;
			// cout<<"DP"<<DP[0][0]<<endl;
			continue;
		}else if(i==0){
			DP[i][j]=false;
			continue;
		}
		DP[i][j] = DP[i-1][j] || DP[i-1][((j-num[i-1]%k)+k)%k];
		//cout<< i-1 << " " << j << ": " << DP[i-1][j] << " "
		// << i-1 << " " << ((j-num[i-1]%k)+k)%k << ": " << DP[i-1][((j-num[i-1]%k)+k)%k] <<endl;
	}
	//cout << endl;
}
// for(int i=0; i<=k; i++){
// 	for(int j=0; j<=n; j++){
// 		cout << DP[j][i] << " ";
// 	}
// 	cout<<endl;
// }

return DP[n][k];
}

int a, b;
int sum=0;
int main(){
//ifstream cin("cin.txt");
cin >> a >> b;
for (int i = 0; i < a; ++i)
{
	cin>>num[i];
	num[i]=abs(num[i]);
	sum+=num[i];
	num[i]*=2;
}
sum %= b; //this is the goal sum modulo
f(a,b);
//cout << sum <<endl;
cout << (DP[a][sum] ? "Divisible" : "Not divisible") << endl;

return 0;
}

//Things I learned/
//using abcd as input vars is totally legit, you can use more suitable names inside a function
//don't worry about how you are going to print out your 2-d array, just keep your addresses consistent
//print out statements can be incorrect too