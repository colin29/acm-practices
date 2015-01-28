#include <iostream>
#include <string>
#include <list>
#include <cstring>
#include <fstream>
#include <ctime>
#include <queue>   
#include <climits>
#include <algorithm>

#include <fstream>
#include <math.h>
using namespace std;


/************************************************************
 
Class Graph represents a Graph [V,E] having vertices V and
edges E.
 
************************************************************/
class Graph {
    private:
        int n; /// n is the number of vertices in the graph
        int **A; /// RESIDUAL GRAPH
        bool *visited; //flag 
        int *origin; //for node X, stores the value of the node which discovered X
    public:
        Graph(int size = 2);
        ~Graph();
        bool isConnected(int, int);
        int getCapac(int, int);
        void addEdge(int u, int v, int w=1);
        int BFS(int start, int goal);
        void reducCapac(int, int, int removed);
        void addCapac(int, int, int added);
        void printTable();
};
 
Graph::Graph(int size) {
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
    visited=new bool[n];
    for (i=0; i<n; i++){
    	visited[i]=false;
    }
    origin = new int[n];
}
 
Graph::~Graph() {
    for (int i = 0; i < n; ++i)
    delete [] A[i];
    delete [] A;
}
 
 
/******************************************************
Checks if two given vertices are connected by an edge
@param u vertex
@param v vertex
@return true if connected false if not connected
******************************************************/
bool Graph::isConnected(int u, int v) {
    return (A[u][v] > 0);
}
int Graph::getCapac(int u, int v){
	return (A[u][v]);
}
void Graph::reducCapac(int u, int v, int removed){
	A[u][v]-=removed;
}
void Graph::addCapac(int u, int v, int added){
	A[u][v]+=added;
}
 
/*****************************************************
adds an edge E to the graph G.
@param u vertex
@param v vertex
*****************************************************/
void Graph::addEdge(int u, int v, int w) {
    A[u][v] = w;
}



/**takes in the goal node, /returns the path capac if found, -1 if not. */
/**Sets path to the path from start to goal, not including the goal*/
std::list<int> path;
int Graph::BFS(int start, int goal){ 
	//*****Fill in THIS FUNCTION*****
	std::queue<int> q;
	q.push(start);
	for(int i=0; i<n;i++)
		{
			visited[i]=false;
			//cout<< "visited" << " " << i << ": " << visited[i] <<endl;
		}
	visited[start]=true;

	while(true){
		if(q.empty())
			return -1; //no path

		int a = q.front();
		q.pop();
		//cout<<"Popped: " << a<<endl;
		if(a==goal){
			//cout<<"Reached goal node."<<endl;
			break; //success
		}
		for (int j=0; j<n; j++){
			if (!visited[j] && isConnected(a, j)){
				visited[j]=true;
				origin[j]=a; //mark that j was discovered from node a
				q.push(j);
			}
		}	
	}
	//Found path, now find path capac and update nodes.
	path.clear();
	int curr = goal;
	
	while(true){
		path.push_front(curr);
		if(curr==start) break;
		curr = origin[curr];
	}
	//cout<<"Path taken: " << endl;
	int capac = INT_MAX;
	for (std::list<int>::const_iterator iterator = path.begin(); *iterator != goal; ++iterator) { //the last iteration is on edge {vertex, goal}
		int next = *(++iterator);
		iterator--;
		int thisCapac = getCapac(*iterator,next);
		//cout<<"Capacity of edge: " << *iterator << ", " << next << ": " << thisCapac<<endl;
		if(getCapac(*iterator,next) < capac)
			capac = thisCapac;
	   // std::cout << "Node " << *iterator<<endl;
	}
	for (std::list<int>::const_iterator iterator = path.begin(); *iterator != goal; ++iterator) { //the last iteration is on edge {vertex, goal}
		int next = *(++iterator);
		iterator--;
		reducCapac(*iterator,next, capac);
		addCapac(next, *iterator, capac); //add capacity to the backwards edge
		int thisCapac = getCapac(*iterator,next);
		//cout<<"New capacity of edge: " << *iterator << ", " << next << ": " << thisCapac<<endl;
	}
	return capac; //return capacity of path

}

void Graph::printTable(){
	for(int i=0; i<n;i++){
		cout<<"Row " << i%10 << "  ";
		for(int j=0; j<n; j++){
			cout<<A[i][j]%10;
		}
		cout<<endl;
	}
	cout<<endl;
}
	
int main() {
	//ifstream cin("testInput.txt");

while(!cin.eof()){
    int n, m, sec, vel;
    pair<double, double>* g; //gophers
    pair<double, double>* h; //holes
   
    cin >> n >> m >> sec >> vel;
    //cout<< n << ", " << m << ", " << sec << ", " << vel << endl;

    g = new pair<double, double>[n];
    h = new pair<double, double>[m];
   	Graph BP(n+m+2);
   
    for(int i=0; i<n;i++){ //gophers
        cin >> g[i].first>> g[i].second;
        //cout << "Gopher " << " : " << g[i].first << ", " << g[i].second <<endl;
    }
    for(int i=0; i<m;i++){ //holes
        cin >> h[i].first >> h[i].second;
        //cout << "Hole " << " : " << h[i].first << ", " << h[i].second <<endl;
    }

   // cout<<"N, M: "<<n<<", " <<m;
    double dx = 0; double dy = 0;
    for(int i=0; i<n;i++){ //gophers
    	for(int j=0; j<m; j++){ //holes
    		dx=g[i].first-h[j].first;
    		dy=g[i].second-h[j].second;
    		//cout<< "dx: " <<dx <<" dy: " << dy <<endl;
    		//cout<<"distance: " << pow(dx*dx+dy*dy, 0.5);
    		if(pow(dx*dx+dy*dy, 0.5) <= vel*sec)
    			{BP.addEdge(i, n+j); //adds with weight 1;
    			//cout << "Golpher " << i << " can reach hole " << j <<endl;
    			}
    	}
    }

    // n=5; m=5;

    // Graph BP(5+5+2);
    // BP.addEdge(0, 0+5);
    // BP.addEdge(0, 1+5);  
    // BP.addEdge(1, 0+5);
    // BP.addEdge(2,1+5);
    // BP.addEdge(2,2+5);
    // BP.addEdge(3,2+5);
    // BP.addEdge(3,3+5);
    // BP.addEdge(3,4+5);
    // BP.addEdge(4,4+5);

     //BP.printTable();

    int start = n+m+1-1;
    int goal =  n+m+2-1;

    for(int i=0; i<n;i++){
    	BP.addEdge(start, i, 1);
    }
    // BP.printTable();
    for(int j=0; j<m;j++){
    	BP.addEdge(n+j, goal, 1);
    }

     //BP.printTable();

    int totalCapac = 0;
    while(true){
    	int c = BP.BFS(start, goal);
    	//cout<<"BFS from " << start<< " to " << goal<< " c: " << c << endl;
    	if(c>0){
    		totalCapac+=c;
    		//cout<<"Added Capacity:" << c << endl;
    	}else break;
    	
    }
	 //cout<<"Max Capacity: " << totalCapac << endl;
	 cout<<n-totalCapac<<endl;

	 //return 0;
	 }
    /** Creates a graph with 12 vertices */
  //   Graph g(12);
 
  //   /** Adds edges to the graph */
  //   g.addEdge(1, 2); g.addEdge(1, 3);
  //   g.addEdge(2, 4); g.addEdge(3, 4);
  //   g.addEdge(3, 6); g.addEdge(4 ,7);
  //   g.addEdge(5, 6); g.addEdge(5, 7);
  //   clock_t t1;
  //   t1 = clock();

  //   int totalCapac = 0;
  //   while(true){
  //   	if(c>0){
  //   		totalCapac+=c;
  //   	}else break;
  //   	int c = g.BFS(7);
  //   	cout<<"Added Capacity:" << c << endl;
  //   }
	 // cout<<"Max Capacity: " << totalCapac << endl;
}












