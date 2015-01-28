#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <map>
#include <math.h>

const long double EPS = 1e-9;

using namespace std;

const int SIZE_MAX = 15;
int S[SIZE_MAX]; //the split configuration
map<int, int> PF; //prime factorization
vector<int> lookup; //sorted lookup table


vector<int> L;
vector<int> R;
int countMatch(int n){
	for(int i=0; i<n; i++){
		if(S[i]==1){
			L.push(lookup[i])
		}else if (S[i]==2){
			R.push(lookup[i]);
		}
	}
	if(L.empty() || R.empty() || L.front() < R.front())
		return 0;
	int total =1;
	for(int i=0; i<L.size(); i++){
		total*=PF[L[i]]; //multiply by height of stack
	}
	for(int i=0; i<R.size(); i++){
		total*=PF[R[i]]; //multiply by height of stack
	}
	return total;
}

int count(int i, int len){
	if(i==len-1)
		return countMatch(len);
	int total = 0;
	S[i]=0;
	total += count(i+1, len);
	S[i]=1;
	total += count(i+1, len);
	S[i]=2;
	total += count(i+1, len);
	return total;
}


int main(){
	int n;
	while(cin >> n){
		cin.ignore(1);
		cin >> n;

		PF.clear();
		while(n!=1){
			for(int i=2; i<=n; i++){
				if(n%i==0){
					n/=i;
					pair<map<int, int>::iterator, bool> ret = 
					PF.insert(pair<int, int>(i, 1));
					if(!ret.second){
						ret.first->second +=1;
					}
					break;
				}
			}
			cout << n << endl;
		}
		for(auto it = PF.begin(); it!= PF.end(); it++){
			lookup.push(it->first);
			cout << it->first << " " << it->second << endl;
		}
		sort(lookup.begin(), lookup.end());

		//done prime factorization
		memset(S, 0, sizeof S);
		cout << count(0, PF.size()) << endl;
	}

}