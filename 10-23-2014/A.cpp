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
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;

using namespace std;

struct R{
vector<string> par;
ll val;
};

map<string, R> P;
ll win(string s){
	ll count =0;
	vector<string> ss = P[s].par;
	for(string a : ss){
		 // cout << s << " parents are: " << a << endl;
		count += (win(a)/2);
	}
	count +=P[s].val; //for the king
	 // cout << s << " " << log2(count) << endl;
	return count;
}


int main(){
int n, m;
cin >> n >> m;


string s;
cin>> s;
R r;
r.val = 1ll << 51;

P.insert(pair<string, R>(s, r));
for(int i=0; i<n; i++){
string a, b, c;
cin >> a >> b>> c;
r.val=0;
P.insert(pair<string, R>(b, r));
P.insert(pair<string, R>(c, r));
P.insert(pair<string, R>(a, r)).first->second.par.push_back(b);
P.insert(pair<string, R>(a, r)).first->second.par.push_back(c);
}
string heir;
ll best =-1;
for(int i=0; i<m; i++)
{
 string s;
 cin >>s;
 r.val=0;
 P.insert(pair<string, R>(s, r));
 ll val = win(s);
 if(val>best){
 	heir = s;
 	best=val;
 }
}
cout << heir <<endl;


}