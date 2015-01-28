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
typedef std::vector<int> VI;
typedef std::vector<VI> VVI;


using namespace std;

struct P{
bool visited;
bool blocked;
int a, b;
P* par;
};


P G[105][105];

vector<int> path;
int n, m;

int bfs(P s, P e){ 
for(int i=0; i<=n; i++){
	for(int j=0; j<=m; j++){
		G[i][j].visited=false;
		G[i][j].par=0;
	}
}
queue<P> S;
G[s.a][s.b].visited=true;
if(G[s.a][s.b].blocked)
	return 999999;
S.push(G[s.a][s.b]);
bool found=false;
while(!S.empty()){
	P cur = S.front(); S.pop();
	// cout << "popped: " << cur.a << " " << cur.b << endl;
	if(cur.a==e.a && cur.b==e.b){
		// cout << "found" << endl;
		found =true;
		break;
	}
	if(cur.a+1>=0 && cur.a+1<=n && G[cur.a+1][cur.b].visited==false && G[cur.a+1][cur.b].blocked==false){
		G[cur.a+1][cur.b].visited=true;
		G[cur.a+1][cur.b].par = &G[cur.a][cur.b];
		S.push(G[cur.a+1][cur.b]);
	}
	if(cur.a-1>=0 && cur.a-1<=n && G[cur.a-1][cur.b].visited==false && G[cur.a-1][cur.b].blocked==false){
		G[cur.a-1][cur.b].visited=true;
		G[cur.a-1][cur.b].par = &G[cur.a][cur.b];
		S.push(G[cur.a-1][cur.b]);
	}
	if(cur.b+1>=0 && cur.b+1<=m && G[cur.a][cur.b+1].visited==false && G[cur.a][cur.b+1].blocked==false){
		G[cur.a][cur.b+1].visited=true;
		G[cur.a][cur.b+1].par = &G[cur.a][cur.b];
		S.push(G[cur.a][cur.b+1]);
	}
	if(cur.b-1>=0 && cur.b-1<=m && G[cur.a][cur.b-1].visited==false && G[cur.a][cur.b-1].blocked==false){
		G[cur.a][cur.b-1].visited=true;
		G[cur.a][cur.b-1].par = &G[cur.a][cur.b];
		S.push(G[cur.a][cur.b-1]);
	}
}


int len =0;
if(!found){
	return 999999; //returns 999999 if fail;
}else{ //mark the path taken as all blocked
	P cur = G[e.a][e.b];
	while(true){
		if(!cur.par)
			break;
		G[cur.a][cur.b].blocked=true;
		cur = *(G[cur.a][cur.b].par);
		//cout << cur.a << " " << cur.b << endl;
		len+=1;
	}
	G[cur.a][cur.b].blocked=true;
	return len;
}
}

void clearBlocked(){
for(int i=0; i<=n; i++){
	for(int j=0; j<=m; j++){
		G[i][j].blocked=false;
	}
}
}

void printBlocked(){
for(int i=0; i<=n; i++){
	for(int j=0; j<=m; j++){
		cout << G[i][j].blocked << " ";
	}
	cout << endl;
}
cout << endl;
}

int main(){
cin >> n >> m;

P p;
p.blocked=false;
p.visited =false;
for(int i=0; i<=n;i++){
	for(int j=0; j<=m; j++){
		G[i][j]=p;
		G[i][j].a=i;
		G[i][j].b=j;
	}
}

P a1, a2, b1, b2;
cin >> a1.a >> a1.b;
cin >> a2.a >> a2.b;
cin >> b1.a >> b1.b;
cin >> b2.a >> b2.b;

int len=0, best =8888888;
clearBlocked();
len=-2; //one vertix double counted, edge count is another -1
for(int i=min(a1.a, a2.a); i<=max(a1.a, a2.a); i++){  //draw L shape with the vertical coming out from a1: b=a1.b;
	G[i][a1.b].blocked = true;
	len+=1;
}
for(int i=min(a1.b, a2.b); i<=max(a1.b, a2.b); i++){
	G[a2.a][i].blocked = true;
	len+=1;
}
len += bfs(b1, b2);
best = (len<best ? len : best);
//cout << "best: " << best << " len: " << len << " L-a1" << endl;

clearBlocked();
len=-2;
for(int i=min(a1.b, a2.b); i<=max(a1.b, a2.b); i++){//draw the other L shape with the horizontal coming out from a1: a=a1.a;
	G[a1.a][i].blocked = true;
	len+=1;
}
for(int i=min(a1.a, a2.a); i<=max(a1.a, a2.a); i++){  
	G[i][a2.b].blocked = true;
	len+=1;
}
len += bfs(b1, b2);
best = (len<best ? len : best);
//cout << "best: " << best << " len: " << len << " L-a2" << endl;
//repeat for b;

clearBlocked();
len=-2; //one vertix double counted, edge count is another -1
for(int i=min(b1.a, b2.a); i<=max(b1.a, b2.a); i++){  //draw L shape with the vertical coming out from b1: b=b1.b;
	G[i][b1.b].blocked = true;
	len+=1;
}
for(int i=min(b1.b, b2.b); i<=max(b1.b, b2.b); i++){
	G[b2.a][i].blocked = true;
	len+=1;
}
len += bfs(a1, a2);
best = (len<best ? len : best);
//cout << "best: " << best << " len: " << len << " L-b1" << endl;

clearBlocked();
len=-2;
for(int i=min(b1.b, b2.b); i<=max(b1.b, b2.b); i++){//draw the other L shape with the horizontal coming out from b1: b=b1.a;
	G[b1.a][i].blocked = true;
	len+=1;
}
for(int i=min(b1.a, b2.a); i<=max(b1.a, b2.a); i++){  
	G[i][b2.b].blocked = true;
	len+=1;
}
len += bfs(a1, a2);
best = (len<best ? len : best);
//cout << "best: " << best << " len: " << len << " L-b2" << endl;

// now try bfs with a first;
clearBlocked();
len=0;
G[b1.a][b1.b].blocked=true;
G[b2.a][b2.b].blocked=true;
len += bfs(a1, a2);
G[b1.a][b1.b].blocked=false;
G[b2.a][b2.b].blocked=false;
len += bfs(b1, b2);
best = (len<best ? len : best);
//cout << "best: " <<  best << " len: " << len << " BFS-a" << endl;

//b first
clearBlocked();
len=0;
G[a1.a][a1.b].blocked=true;
G[a2.a][a2.b].blocked=true;
len += bfs(b1, b2);
G[a1.a][a1.b].blocked=false;
G[a2.a][a2.b].blocked=false;
len += bfs(a1, a2);
best = (len<best ? len : best);
//cout << "best: " << best << " len: " << len << " BFS-b" << endl;

if(best>10000){
	cout << "IMPOSSIBLE" << endl;
}else{
	cout << best << endl;
}


//cout << "shortest path: " << bfs(a1, a2) << endl;


}