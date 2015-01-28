#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue> 
#include <string>

using namespace std;

typedef long long int ll;
typedef pair<int, int> P;

struct c {
c() : N(true), E(true), W(true), S(true), seen(false) {} //default constructor, I think.
bool N, E, W, S;
bool seen;
int x, y;
char dir; //dir travelled to discover this tile:
//one of 'N', 'E', etc.
};



int main(){
P s, e, ws, we; //w=walls

while(cin >> s.first && cin >> s.second && s.first){
cin >> e.first >> e.second;

c maze[6][6]; //in comments I will refer to cell 1-6
//for addressing elements I will just add a "-1"
//abusing the while loop so the maze re inits every test case;

// cout<<"s: " << s.first << " " << s.second <<endl;
// cout<<"e: " << e.first << " " << e.second <<endl;

//refresh board state;

for(int i=0; i<3; i++){
	cin >> ws.first >>ws.second;
	cin >> we.first >>we.second;
	// cout<<"ws: " << ws.first << " " << ws.second <<endl;
	// cout<<"we: " << we.first << " " << we.second <<endl;
	//walls are at least 1 length
	if(ws.first==we.first){ //wall endpoints have the same x,so up+down
	//cells affected: 
		for(int j=ws.second+1; j<=we.second; j++){
			if(ws.first >=1){
				maze[ws.first -1][j -1].W = false;
				// cout<<"applied vertical wall (W) to: " << ws.first << " " << j <<endl;
			}
			if(ws.first+1 <=6){
				maze[ws.first+1 -1][j -1].E = false;
				// cout<<"applied vertical wall (E) to: " << ws.first+1 << " " << j <<endl;
			}
			
		}
	} else { //walls have the same y, so left+right
		for(int j=ws.first+1; j<=we.first; j++){
			if(ws.second >=1){
				maze[j -1][ws.second -1].S = false;
				// cout<<"applied horz wall (S) to: " << j << " " << ws.second <<endl;
			}
			if(ws.second+1 <=6){
				maze[j -1][ws.second+1 -1].N = false;
				// cout<<"applied horz wall (N) to: " << j << " " << ws.second+1 <<endl;
			}
			
		}

	}
} //walls done applying
//now apply boundaries
for(int i=0; i<6; i++){
	maze[i][0].N=false;	
}
for(int i=0; i<6; i++){
	maze[i][5].S=false;	
}
for(int i=0; i<6; i++){
	maze[0][i].E=false;	
}
for(int i=0; i<6; i++){
	maze[5][i].W=false;	
}
//apply cell x, y
for(int i=0; i<6; i++){
	for (int j = 0; j < 6; j++)
	{
		maze[i][j].x = i+1;
		maze[i][j].y = j+1;
	}
}

//do BPS
//push starting node on queue
queue<c> nodes;
c& start = maze[s.first -1][s.second -1];
start.seen = true;
nodes.push(start); //inserts the initial node (copies);

while(true){
if(nodes.empty()){
	// cout<<"Error queue empty!" << endl;
	break;
}	

c& a = nodes.front(); //a will re-init right after pop so OK
// cout << "popping: " << a.x << " " << a.y << " " <<  a.dir <<endl;

// for(int j=0; j<6; j++){
// 	for (int i = 0; i < 6; i++)
// 	{
// 		cout << maze[i][j].seen << " ";
// 	}
// 	cout<<endl;
// }

if(a.x==e.first && a.y == e.second){
	// cout<<"reached end"<<endl;
	//reached end, traverse back
	string path = "";
	while(!(a.x==s.first && a.y==s.second)){
		path += a.dir;
		// cout<<"appended:" << a.dir <<endl;
		if(a.dir=='N'){ //go in the opposite direction
			a=maze[a.x -1][a.y+1 -1];
		}else if(a.dir == 'S'){
			a=maze[a.x -1][a.y-1 -1];
		}else if(a.dir == 'W'){
			a=maze[a.x+1 -1][a.y -1];
		}else if(a.dir == 'E'){
			a=maze[a.x-1 -1][a.y -1];
		}else{
		// cout<<"Error: a.dir is none of NWES"<<endl;
		break;
	}
	}
	// cout<<"reached start by trace (or error): " << path <<endl;
	reverse(path.begin(), path.end());
	cout<< path <<endl;
	break;
}

if(a.N){
	c& z = maze[a.x -1][a.y-1 -1];
	if(!z.seen){
	z.seen = true;
	z.dir = 'N';
	nodes.push(z);
	// cout<<"pushed (N): " << a.x  << " " << a.y-1 <<endl;
	// cout<<"Z.x, Z.y: "<< z.x  << " " << z.y <<endl;
}
}
if(a.S){
	c& z = maze[a.x -1][a.y+1 -1];
	if(!z.seen){
	z.seen = true;
	z.dir = 'S';
	nodes.push(z);
	// cout<<"pushed (S): " << a.x  << " " << a.y+1 <<endl;
}
}
if(a.E){
	c& z = maze[a.x-1 -1][a.y -1];
	if(!z.seen){
	z.seen = true;
	z.dir = 'W';
	nodes.push(z);
	// cout<<"pushed (E): " << a.x-1  << " " << a.y <<endl;
}
}
if(a.W){
	c& z = maze[a.x+1 -1][a.y -1];
	if(!z.seen){
	z.seen = true;
	z.dir = 'E';
	nodes.push(z);
	// cout<<"pushed (W): " << a.x+1  << " " << a.y <<endl;
}
}
nodes.pop(); //done working with a;

} //end of BFS

//follow path back to start, appending the path to a string

//reverse string and print;


}
}