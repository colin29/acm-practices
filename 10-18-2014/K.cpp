#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <queue>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;


struct P{
char flag;
ll dps;
ll time;
};

struct comp{
bool operator()(P p1, P p2){
	return p1.time > p2.time;
}
};

int main(){
int t;
cin >> t;
while(t--){
	ll n, h;
	cin >> n >> h;

	priority_queue<P, vector<P>, comp> Q;

	ll sum=0;
	for(int i=0; i<n;i++){ //populate event queue.
		P a;
		ll s, t, e;
		cin >> s >> t >> a.dps;
		e=s+t;
		a.flag = 'S';
		a.time = s;
		Q.push(a);

		a.flag='E';
		a.time = s+min(t, h);
		Q.push(a);

		a.flag = 'F';
		a.time= s+max(t, h);
		Q.push(a);

		a.flag = 'O'; //owari
		a.time = s+t+h;
		Q.push(a);

		sum+=t*a.dps;
	}

	ll prevent =0;
	ll dps =0;
	ll prev = 0;
	ll timeElap;
	ll best = 0;
	while(!Q.empty()){
		P cur = Q.top();
		// cout << "processing event: " << cur.flag << " " << cur.time << " " << cur.dps << endl;
		Q.pop();
		timeElap = cur.time - prev;
		prev= cur.time;
		prevent += dps * timeElap;
		// cout << dps << " " << timeElap << endl;

		if(cur.flag=='S'){
			dps+=cur.dps;
		}else if(cur.flag == 'E'){
			dps-=cur.dps;
		}else if(cur.flag == 'F'){
			dps-=cur.dps;
		}else{
			dps+=cur.dps;
		}
		best = ((prevent>best)?prevent:best);


	}
	cout << sum-best << endl;
}


}