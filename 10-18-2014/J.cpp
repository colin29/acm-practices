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

struct Q{
int num;
double x, y;
int min;
};

struct comparator{
bool operator()(Q q1, Q q2){
return q1.min>q2.min;
}
};



int main(){
int t;
cin >> t;
while(t--){
	int sx, sy, ex, ey, r, j;
	cin >> sx >> sy >> j;
	cin >> ex >> ey >> r;
	int n;
	cin >> n;
	vector<Q> R;
	for(int i=0; i<n; i++){
		Q a;
		cin >> a.x >> a.y;
		a.min=999999999;
		a.num=i;
		R.push_back(a);
	}
	priority_queue<Q, vector<Q>, comparator> P;
	Q a;
	a.x = sx; a.y=sy; a.min=0; a.num=0;
	P.push(a);
	a.x = ex; a.y=ey; a.min = 999999999; a.num=n;
	R.push_back(a);
	bool init = true;
	while(!P.empty()){
		Q cur = P.top();
		 // cout << "paid " << cur.min << ", " << cur.num << endl;
		if(cur.num == n && !init){
			cout << cur.min << endl;
			// for(int i=0; i<R.size(); i++){
			// 	cout << R[i].min << " ";
			// }
			// cout << endl;
			break;
		}
		P.pop();
		if(cur.min<=R[cur.num].min){

			
			for(int i=0; i<R.size();  i++){
				double dis = sqrt((cur.x-R[i].x)*(cur.x-R[i].x)+(cur.y-R[i].y)*(cur.y-R[i].y));
				// cout << "dis " <<  dis << endl;
				
				
				// cout << "dis " <<  dis << endl;
				int cost = (ceil(dis/j)-1);
				cost = max(0, cost);
				cost += cur.min;

				if(i==n){
					// cout << "dis: " << dis << endl;
					if(dis<=r){
						cost=0;
					}else{
					dis-=r;
					int cost2= (cur.min + (ceil(dis/j)));
					cost= max(0, cost2);
					}
				}
			
				
				 // cout << "go to node: " << i << " cost: " << cost << " min: " << R[i].min << endl;
				if(cost<R[i].min){
					R[i].min=cost;
					P.push(R[i]);
					  // cout << "pushed=== " << cost << ", " << i << endl;
				}

			}
			if(!init)
				R[cur.num].min = -999999; //don't want to reinvestigate node, even if we find a same cost path.
		}
		init=false;
		
	}


}

}