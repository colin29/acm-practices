#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <map>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

map<char, ll> M;
vector<char> A;

ll fact(ll n){
	if(n==0){
		return 1;
	}else{
		return n*fact(n-1);
	}
}

ll comb(ll n){ //returns number of combinations;
	ll a=fact(n);
	for(map<char, ll>::iterator it = M.begin(); it!=M.end(); it++){
		if(it->second!=0){
			a/=fact(it->second);
		}
	}
	return a;
}

bool done;
void gogo(ll id, ll rem){ //at the end, A should contain the requested anagram
	// cout << "called gogo: " << id << " " << rem << endl;
	ll count = 0;
	if(rem==0){
		done = true;
		return;
	}
	for(map<char, ll>::iterator it = M.begin(); it!=M.end(); it++){
		if(it->second>0){
			it->second-=1;
			count += comb(rem-1);
			// cout << "count is " << count << endl;
			if(id<=count){ //if id is within this set of combintations, then pursue the sequence.
				A.push_back(it->first);
				gogo(id-count + comb(rem-1), rem-1);
				if(done){
				return;
				}
			}
			it->second+=1;
		}
	}
	// cout << "Error, id is greater than all combinations" << endl;
}

int main(){
ll n;
string w;
while(cin>>w && w!="#" ){
if(!(cin >> n) || n==0){
	break;
}
A.clear();
M.clear();
done = false;
//populate map;
for(int i=0; i<w.length(); i++){
	M[w[i]]++;
}
gogo(n, w.length());

for(int i=0; i<A.size(); i++){
	cout << A[i]; 
}
cout << endl;
}



}