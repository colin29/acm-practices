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

using namespace std;

const int M = 103, N=103;
bool adjmat[M][N], seen[N]; int matchL[M], matchR[N], m, n;
bool bpm(int u) { // Can we find augmenting path starting from u
  for(int v = 0; v < n; v++) if(adjmat[u][v] && !seen[v]) { seen[v] = true;
    if(matchR[v] == -1 || bpm(matchR[v]) ) { matchL[u] = v, matchR[v] = u;
      return true; } }
  return false; }

int main(){
int r;
cin >> r;
while(r--){
	memset(matchL,-1,sizeof matchL); 
	memset(matchR,-1,sizeof matchR);
	int k;
	cin >> n >> m >> k;
	int temp=max(n, m);
	m=min(n, m);
	n=temp;
	memset (adjmat, false, sizeof adjmat);
	for(int i=0; i<k; i++){
		double x, y;
		cin >> x >> y;
		adjmat[(int) x][(int) y] = true;
	}

	int cnt = 0;
	for(int i = 0; i < m; i++) {
		memset(seen, 0, sizeof seen);
    if( bpm(i) ) cnt++; // matchL[i] is the match
	}
cout << cnt << endl;
}
return 0;
}