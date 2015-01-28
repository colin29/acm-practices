#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int magic(const string& sub, const string& k){
	int l = sub.length();
	string m;
	for(int i=l; i>0; i--){ //i is length of affix-suffix
		m=sub.substr(l-i, l);
		if(m==k.substr(0, i)){
			return i;
		}
	}
	return 0;
}

const int NUML = 36;
int main(){

	int t;
	cin >>t;
	for (int i = 0; i < t; ++i)
	{
		int n, lsub;
		string ik;
		cin>>n;
		cin>>ik;
		lsub = ik.length();

		if(lsub>n){
			cout<<0<<endl;
			continue;
		}
		// cout << magic("a", "abc") <<endl;
		// cout << magic("ab", "abc") <<endl;
		// cout << magic("cab", "abc") <<endl;
		// cout << magic("cabc", "abc") <<endl;
		// cout << magic("cabd", "abc") <<endl;

		int** DP = new int*[n+1]; //(n, k)
		for(int j=0; j<=n; j++){ //iterate over n
			DP[j]= new int [n+1];
			for(int k=0; k<=n; k++){
			DP[j][k]=0;
			}
		}
		//memset(DP, 0, (n+1)*(n+1)); WHY YOU NO WORK

		DP[1][0]=NUML-1; //if N is 1...or if k is 1
		DP[1][1]=1;

		for(int j=1; j<n; j++){ //iterate over n (NOT j<=n, BEWARE OF DP'ING OFF THE END OF THE TABLE)
			for(int k=0; k<=n; k++){ //over k
				if(DP[j][k]==0) continue;
				
		 		if(k==lsub){
					DP[j+1][k] += NUML*DP[j][k];
					DP[j+1][k] %= 100003;
					continue;
				}
				
				for(int e=0; e<26; e++){
				char r = 'a' + e;
				string s = ik.substr(0, k);
				s += r;
				int l = magic(s, ik);
				DP[j+1][l] += DP[j][k];
				DP[j+1][l] %= 100003;

				}
				for(int e=0; e<10; e++){
				char r = '0' + e;				
				string s = ik.substr(0, k);
				s += r;
				int l = magic(s, ik);
				DP[j+1][l] += DP[j][k];
				DP[j+1][l] %= 100003;
				}
			}
		}
		// for(int j=0; j<=n; j++){
		// 	for(int k=0; k<=n; k++){ 
		// 	cout<< DP[k][j] << " ";
		// 	}
		// 	cout<<endl;
		// }
		int total=0;
		total+=DP[n][lsub];
		total%=100003;

		cout<<total<<endl;

	}

}