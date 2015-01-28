#include <bits/stdc++.h>
 
using namespace std;
 
vector<int> g[100005], grev[100005], topo;
int deg[100005], dist[100005];
long long ans[100005];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<char, int> m({{'H', 0}, {'U', 1}, {'E', 2}});
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        cin >> s;
        for (int i = 0; i <= n+1; i++) {  //clear g, grev, etc.
            ans[i] = dist[i] = deg[i] = 0;
            g[i].clear();
            grev[i].clear();
        }
 
        for (int i = 0; i < n-1; i++) { //populate adj. list H->U, E->U, U>H
            int x, y; cin >> x >> y;
            x--, y--;
            if ((m[s[x]]+1)%3 ==  m[s[y]]) {
                g[x].push_back(y);
            } else if ((m[s[y]]+1)%3 == m[s[x]]) {
                g[y].push_back(x);
            }
        }
         
        for (int i = 0; i < n; i++) { //connect a node to all the H's, and all the E's to another node.
            if (s[i] == 'H') {
                g[n].push_back(i);
            } else if (s[i] == 'E') {
                g[i].push_back(n+1);
            }
        }
 
        //topo sort then dp
        for (int i = 0; i <= n+1; i++) { //generate g-reverse... each node has a list of stuff pointing to it's parent. 
            for (int c : g[i]) {
                grev[c].push_back(i);
                deg[c]++;       //count degree. H's will always have degree of at least 1.
            }
        }
 
        queue<int> q;
        for (int i = 0; i <= n+1; i++) {
            if (deg[i] == 0) { //if the degree is 1 (this includes the super-source to all the H's), add it to the queue.
                q.push(i); //push the id of the node to a queue.
                topo.push_back(i);
                dist[i] = -10000000; //reject all starting nodes...
            }
        }
        dist[n] = 0; //except the one that represents all the 'H' starting paths
 
        topo.clear();
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int c : g[u]) { //for all of a node's children
                deg[c]--; //decrement their degree
                if (deg[c] == 0) { //if they have no remaining parents, put them in. The sink node (n+1) will be last)
                    q.push(c);
                    topo.push_back(c); //add all non-source nodes (includes every 'H' node) in topological order.
                }
            }
        }
         
        for (int v : topo) {
            dist[v] = 0;
            for (int c : grev[v]) {  //starting from the tops of the tree, each node is the (max length among it's parents) +1.
                dist[v] = max(dist[c]+1, dist[v]); //note that the source node dist[n] was set to 0 earlier.
            }
        }
 
        ans[n] = 1;
        for (int v : topo) {
            for (int c : grev[v]) {
                if (dist[v] == dist[c]+1) {
                    ans[v] += ans[c]; //accumulate answer count from...all parents, if their dist is consistent with the longest distance. -100000 dist 'blocked' nodes are ignored
                }
            }
        }
 
        for (int i = 0; i < dist[n+1]-1; i++) { //print out longest string
            cout << "HUE"[i%3];
        }
        cout << '\n';
        cout << ans[n+1] << '\n';
    }
}
