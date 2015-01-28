#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <queue>
#include <math.h>

const long double EPS = 1e-9;

using namespace std;

struct P {
double x;
double y;
};

struct N{
double x;
double y;
double time; //time to come up to this point
double est; //guranteed not to be an overestimate, estimate of the time required using those cannons.
vector<int> path;
};

bool comp(const N &n1, const N &n2){
		return n1.est> n2.est;
}

int main(){
double ix, iy, dx, dy;
cin >> ix >> iy >> dx >> dy;
int n;
cin >> n;

vector<P> C;
for (int i = 0; i < n; ++i)
{
	P l;
	cin >> l.x >> l.y;
	C.push_back(l);	
}

priority_queue<N, vector<N>, decltype(&comp)> Q(comp);
N start;
start.x=ix; start.y=iy;
double upperBound;
start.time = 0; 
start.est = -1; // marker, don't worry about it.
upperBound = sqrt((dx-ix)*(dx-ix) + (dy-iy)*(dy-iy))/5;
// cout << "initial upper bound: " << upperBound << endl;

if(n==0){
	cout << upperBound << endl;
	return 0;
}
Q.push(start);

while(true){
	// cout << "entering loop" << endl;
	if(Q.empty()){
		cout << upperBound << endl;
		break;
	}
	N cur = Q.top();
	Q.pop();
	double disToEnd = sqrt((cur.x-dx)*(cur.x-dx) + (cur.y-dy)*(cur.y-dy));
	double l;
	if (cur.est==-1){
	l=disToEnd/5;
	}else{
	l = cur.time + 2 + abs(disToEnd-50)/5;
	}
	 // for(int j=0; j<cur.path.size(); j++){
	 // 		cout << cur.path[j];
	 // 	} cout << endl;
	 // cout << "actual: " << l << endl;
	if(l<upperBound){upperBound=l;}

	N next;
	for(int i=0; i<n; i++){
		next.x = C[i].x;
		next.y = C[i].y;
		if(cur.x == next.x && cur.y == next.y && cur.est != -1)
			continue;
		double nextToEnd = sqrt((next.x-dx)*(next.x-dx) + (next.y-dy)*(next.y-dy));
		
		double disToNext = sqrt((next.x-cur.x)*(next.x-cur.x) + (next.y-cur.y)*(next.y-cur.y));
		double timeToNext = ((cur.est==-1)? disToNext/5 : 2 + abs(disToNext-50)/5);
		next.time = cur.time + timeToNext;
		next.est = next.time + nextToEnd/25;
		next.path = cur.path;
		
		
		if(find(next.path.begin(), next.path.end(), i) != next.path.end()) {
			// cout << "repeat truncated" << endl;
			continue;}
		next.path.push_back(i);
		 // cout << "path through " << i << " time: " << next.time << " est: " << next.est << endl;
		// cout << disToNext/5 << endl;
		if(next.est<upperBound) {Q.push(next);}
	}
}




}