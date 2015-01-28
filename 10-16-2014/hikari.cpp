#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

const int key = 315;
int P[5][5][5];
vector<int> rem;


struct Q{
int a, b, c;
};

vector<Q> spaces;
vector<int> holding;
bool print_holding(){
	for(int i=0; i<holding.size(); i++){
			cout << holding[i] << " ";
	}
	cout << endl;
}

bool check(int a,int b,int c){
int sum=0;
bool skip = false;
for(int i=0; i<5; i++){
if(P[i][b][c]==-1){
	skip=true;
}else{
sum+=P[i][b][c];
}
}
if(sum>315)
	return false;
if(!skip && sum != key)
	return false;

cout << "hi"<< endl;
sum=0;
skip=false;
for(int i=0; i<5; i++){
if(P[a][i][c]==-1){
	skip=true;
}else{
sum+=P[a][i][c];
}
}
if(!skip){
	cout << "sum of column: " << sum << endl;
}
if(sum>315)
	return false;
if(!skip && sum != key){
	return false;
}


sum=0;
skip = false;
for(int i=0; i<5; i++){
if(P[a][b][i]==-1){
	skip=true;
}else{
	sum+=P[a][b][i];
}
}
if(sum>315)
	return false;
if(!skip && sum != key)
	return false;


return true;
}

bool done = false;

bool solve(int a, int b, int c, int placed){

	print_holding();
	
	if(check(a, b, c)==false)
		return false;
	cout << "a, b, c, placed: " << a << " " << b << " " << c << " placed:" << placed << endl;
	if(placed == spaces.size()){
		cout << "solved!" << endl;
		done = true;
		return true;
	}
	for(int i=0; i<rem.size(); i++){

		if(rem[i]==-1)
			continue;
		Q q = spaces[placed];
		P[q.a][q.b][q.c] = rem[i];
		holding.push_back(rem[i]);
		rem[i]=-1;
		

		solve(q.a, q.b, q.c, placed+1);
		if(done)
			return true;

		holding.pop_back();
		rem[i]=P[q.a][q.b][q.c];
		P[q.a][q.b][q.c] = -1;
		}
		
		return false;		
	
}

int main(){
	int a;
	for(int i=0; i<5; i++){ //level, blue is 0
		for(int j=0; j<5; j++){ //row, topmost is 0
 			for(int k=0; k<5; k++){ //column, leftmost is 0
				cin >> a;
				P[i][j][k] = a;
				if(a==-1){
					Q b;
					b.a=i;
					b.b=j;
					b.c=k;
					spaces.push_back(b);
				}
			}
		}
	}
	int n;
	
	while(cin>>n){
		rem.push_back(n);
	}
	cout << "rem.size(): " << rem.size() << endl;
	cout << "spaces.size(): " << spaces.size() << endl;

	cout << solve(0, 0, 0, 0) << endl;
	for(int i=0; i<5; i++){ //level, blue is 0
		cout << "Level: " << i << endl;
		for(int j=0; j<5; j++){ //row, topmost is 0
 			for(int k=0; k<5; k++){
 				cout << P[i][j][k] << " ";
 			}
 			cout << endl;
 		}
 		cout << endl;
 	}




}