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

struct E{
int id;
char type;
double ang;
};

struct compE{
operator()(E e1, E e2){
	return e1.ang > e2.ang; //for min heap
}
};

int main(){
double cx, cy;
int n, x, y;
while(cin>>n>>x>>y && !(n==0 && x == 0 && y==0)){
	
	priority_queue<
	bool active[n];
	memset(active, 0, sizeof active);
	cx=x/2.0;
	cy=y/2.0;
	for(int i=0; i<n; i++){
		double ax, ay;
		cin >> ax >> ay;
		double dx, dy, ang;
		dx=cx-ax;
		dy=cy-ay
		if(dx==0 && dy==0){
			ang = 0;
		}else{
			ang = atan2(dy, dx);
		}

		E e;
		e.id = i;
		e.type = 'S';
		e.ang = ang;

	}

	sort(V.begin(), V.end(), less<double, int>());



}

}