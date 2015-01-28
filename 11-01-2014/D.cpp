#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <queue>
#include <map>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;


struct E{
int time;
char type; //'P' or 'T' -- path or tree
int id;
int megacannon;
};

struct P{
int id;
int x, y;
bool next;
};

struct compT{
bool operator()(E e1, E e2){
	return e1.time > e2.time;
}
};

int main(){

int t, p;
cin >> t >> p;

vector<bool> vis(t, false);
vector<P> trees;

for(int i=0; i<t; i++){
	P a;
	cin >> a.x >> a.y;
	a.id = i;
	a.next = false;
	trees.push_back(a);
}

vector<int> pathV;
vector<int> pathH;

for(int i=0; i<p; i++){
	char c;
	int a;
	cin >> c;
	cin.ignore(1);
	cin >> a;
	if(c=='x'){
		pathV.push_back(a);
	}else{
		pathH.push_back(a);
	}
}



//populate event queue
if(pathV.size()!=0){	
	priority_queue<E, vector<E>, compT> Q;
	for(int i=0; i<trees.size(); i++){
		E e;
		e.time = trees[i].x;
		e.megacannon = trees[i].y;
		e.type='T';
		e.id = i;
		Q.push(e);
	}
	for(int i=0; i<pathV.size(); i++){
		E e;
		e.time= pathV[i];
		e.type='P';
		Q.push(e);
	}

	//linesweep
	map<int, P> active;
	bool firstBlood = false;
	vector<int> wouldBeSeen;
	while(!Q.empty()){
		E e = Q.top(); Q.pop();
		// cout << "event type, time: " << e.type << " " << e.time << endl;
		if(e.type=='T'){ //event is a tree
			wouldBeSeen.push_back(e.id);
			if(active.find(e.megacannon)==active.end()){
				active[e.megacannon]=trees[e.id];
				if(firstBlood==true){
					// cout << "seen a: " << e.id << endl;
					vis[e.id]=true;
				} 
			}else{
				if(active[e.megacannon].next == true){
					active[e.megacannon]=trees[e.id];
					vis[e.id]=true;
					// cout << "seen b: " << e.id << endl;
				}else{
					active[e.megacannon]=trees[e.id];
				}
			}
		}else{ //event is a path
			firstBlood=true;
			for(int i=0; i<wouldBeSeen.size(); i++){
				active[trees[wouldBeSeen[i]].y].next = true;
				 // cout << "seen c: " <<  wouldBeSeen[i] << endl;
				if(wouldBeSeen[i]==active[trees[wouldBeSeen[i]].y].id){
				vis[wouldBeSeen[i]] = true;
				}
			}
			wouldBeSeen.clear();
		}

	}
}
//now do it again
// cout << "doing horizontal lines" << endl;
if(pathH.size()!=0){	
	priority_queue<E, vector<E>, compT> Q;
	for(int i=0; i<trees.size(); i++){
		E e;
		e.time = trees[i].y;
		e.megacannon = trees[i].x;
		e.type='T';
		e.id = i;
		Q.push(e);
	}
	for(int i=0; i<pathH.size(); i++){
		E e;
		e.time= pathH[i];
		e.type='P';
		Q.push(e);
	}

	//linesweep
	map<int, P> active;
	bool firstBlood = false;
	vector<int> wouldBeSeen;
	while(!Q.empty()){
		E e = Q.top(); Q.pop();
		 // cout << "event type, time: " << e.type << " " << e.time << endl;
		if(e.type=='T'){ //event is a tree
			// cout << "id: " << e.id << endl;
			wouldBeSeen.push_back(e.id);
			if(active.find(e.megacannon)==active.end()){
				active[e.megacannon]=trees[e.id];
				if(firstBlood==true){
					// cout << "seen a: " << e.id << endl;
					vis[e.id]=true;
				}
			}else{
				if(active[e.megacannon].next == true){
					active[e.megacannon]=trees[e.id];
					vis[e.id]=true;
					// cout << "seen b: " << e.id << endl;
				}else{
					active[e.megacannon]=trees[e.id];
				}
			}
		}else{ //event is a path
			firstBlood=true;
			for(int i=0; i<wouldBeSeen.size(); i++){
				active[trees[wouldBeSeen[i]].x].next = true;
				// cout << "seen c: " << wouldBeSeen[i] << endl;
				if(wouldBeSeen[i]==active[trees[wouldBeSeen[i]].x].id){
				vis[wouldBeSeen[i]] = true;
				}
			}
			wouldBeSeen.clear();
		}

	}
}

	//count visible trees;

	int seenCount = 0;
	for(int i=0; i<vis.size(); i++){
		if(vis[i]==true)
			seenCount+=1;
	}
	cout << seenCount << endl;

}