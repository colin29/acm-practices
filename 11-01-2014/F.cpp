#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>
#include <queue>

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<double, double> dd;
const ld EPS = 1e-9;

const int N = 1005;
struct P{
int h;
int s, e;
bool visited;
};

struct compMe{
bool operator()(P p1, P p2){
    return p1.h<p2.h;
}
};

P G[N][N];
bool visit[N];

int main(){

priority_queue<P, vector<P>, compMe > Q;

int c, r;
while(cin >> c >> r && (c||r)){
    for(int i=0; i<c; i++){
        for(int j=0; j<c; j++){
            G[i][j].h =-1;
        }
    }
    for(int i=0; i<r ; i++){
        int s, e, h, l;
        cin >> s >> e >> h >> l;
        if(h==-1){
            h= 500000;
        }
        s-=1; e-=1;
        G[s][e].s = s;
        G[s][e].e = e;
        G[s][e].h =h;

        G[e][s].e = s;
        G[e][s].s = e;
        G[e][s].h = h;
    }

    int cs, ce, h;
    cin >> cs >> ce >> h;
    cs -=1; ce -=1;

    P a;

    cout << "cs " << cs << " " << ce << endl;
    int maxh = -1;

    int cur; cur = cs;
    memset(visit, false, sizeof visit);
    for(int i=0; i<c; i++){
        if(!visit[i]){
            a=G[cur][i];
            if(a.h != -1){
                Q.push(a);
                cout << "pushing path** " << a.s << " " << a.e << " " << a.h << endl;
            }
        }
    }
    visit[cs]=true;
    while(!Q.empty()){
        P now;
        now = Q.top(); Q.pop();

        visit[now.e]=true;
        if(now.e == ce){
            cout << "finished!" << endl;
            maxh = now.h;
            break;
        }
        for(int i=0; i<c; i++){
        if(!visit[i]){
            a=G[now.e][i];
            a.h = min(a.h, now.h);
            if(a.h != -1){
                Q.push(a);
                cout << "pushing path " << a.s << " " << a.e << " " << a.h <<  endl;
            }
        }
    }
    }

    cout << "best: " << maxh << endl;


}


    return 0;
}