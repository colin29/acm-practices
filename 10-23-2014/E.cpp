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
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;


using namespace std;

const int X = 20000, Y = 20000;
bool diag1[X+Y]; //1->x+y-1 
bool diag2[X+Y]; //1->x+y-1

bool goingUp;
getDiag(int a, int b){
if(a==1){
	if(goingUp){
		return b;
	}else{
		return y-a+1;
	}
}
if(a==n){
	if(goingUp){
		
	}
}

}

int main(){
int n;
cin >> n;
while (n--){
	int x, y;
	cin >> x >> y;
	int temp = max(x, y);
	y = min(x, y);
	x=temp;

	memset(diag1, 0, sizeof diag1);
	memset(diag2, 0, sizeof diag2);
	int a =0, b=0; //current location;
	int c;

	goingUp = false;
	//simulate the run until a=x;
	if()
	a=x;
	b=
	if(((x-1)/y)%2)
		goingUp = !goingUp;


	
}

}