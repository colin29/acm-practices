#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>
#include <stack>

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<double, double> dd;
const ld EPS = 1e-9;

const int R=12, C=10;
struct Q{
char val;
int visited;
int a, b; //we only use this for the flood fill
};
Q P[R][C];

void compact(){
    for(int i=0; i<C;i++){ //vertical compacting
        vector<char> newcol;
        for(int j=R-1; j>=0; j--){
            if(P[j][i].val!='E')
                newcol.push_back(P[j][i].val);
        }
        for(int j=R-1; j>=0; j--){
            P[j][i].val='E';
        }
        for(int j=0; j<newcol.size(); j++){
            P[R-1-j][i].val = newcol[j];
        }
    }
    for(int i=0, offset=0; i+offset<C;i++){ //horizontal
        bool canEmpty = true;
        for(int j=0; j<R; j++){
            if(P[j][i].val!='E')
                canEmpty=false;            
        }
        if(canEmpty){
            for(int j=i+1; j<C; j++){
                for(int k=0; k<R; k++){
                    P[k][j-1].val=P[k][j].val;
                }
            }
            i-=1;
            offset+=1;
            for(int j=0; j<R; j++){
                P[j][C-1].val='E';
            }
        }
    }
}
int apply_move(int a, int b, bool execute){
// cout << "apply move called " << a << " " << b << " " << P[a][b].val << endl;
stack<Q> S;
for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
        P[i][j].visited = 0;
        P[i][j].a=i;
        P[i][j].b=j;
    }
}
int count =0;

Q cur = P[a][b];    
char good_val = cur.val; 
if(cur.val !='E'){
    P[a][b].visited = 1;
    S.push(cur);
    
}
    while(true){
        if(S.empty()){
            break;
        }
        

        cur = S.top();
        S.pop();

        if(execute)
            P[cur.a][cur.b].val='E';
        count +=1;
         //cout << "cur a, b: " << cur.a << " " << cur.b << endl;
        Q next;
        next.visited=true;
        next.a = cur.a+1; next.b = cur.b;
        if(next.a >=0 && next.a < R && next.b >=0 && next.b <C
            && P[next.a][next.b].visited==0 && P[next.a][next.b].val==good_val){

            P[next.a][next.b].visited=1;
            S.push(P[next.a][next.b]);
        }
        next.a = cur.a-1; next.b = cur.b;
        if(next.a >=0 && next.a < R && next.b >=0 && next.b <C
            && P[next.a][next.b].visited==0 && P[next.a][next.b].val==good_val){

            P[next.a][next.b].visited=1;
            S.push(P[next.a][next.b]);
        }
        next.a = cur.a; next.b = cur.b+1;
        if(next.a >=0 && next.a < R && next.b >=0 && next.b <C 
            && P[next.a][next.b].visited==0 && P[next.a][next.b].val==good_val){

            P[next.a][next.b].visited=1;
            S.push(P[next.a][next.b]);
        }
        next.a = cur.a; next.b = cur.b-1;
        if(next.a >=0 && next.a < R && next.b >=0 && next.b <C 
            && P[next.a][next.b].visited==0 && P[next.a][next.b].val==good_val){

            P[next.a][next.b].visited=1;
            S.push(P[next.a][next.b]);
        }


    }
    if(count>=3 && !execute)
        apply_move(a, b, true);
    return count;
}

int main(){
int t;
while(cin >> t && t){
for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
        Q a;
        cin >> a.val;
        P[i][j] = a;
    }
}

// cout << endl;
// for(int i=0; i<R; i++){
//     for(int j=0; j<C; j++){
//         cout << P[i][j].val << " ";
//     }
//     cout << endl;
// }
// cout << endl;

int a, b; //[a][b]
for(int i=0; i<t; i++){
    char temp;
    cin >> temp;
    b = temp-'a';
    cin >> a;
    a = 12-a;
    apply_move(a, b, false);
    // cout << endl;
// for(int i=0; i<R; i++){
//     for(int j=0; j<C; j++){
//         cout << P[i][j].val << " ";
//     }
//     cout << endl;
// }
// cout << endl;
    compact();
}

// cout << endl;
// for(int i=0; i<R; i++){
//     for(int j=0; j<C; j++){
//         cout << P[i][j].val << " ";
//     }
//     cout << endl;
// }
// cout << endl;
int count =0;
for(int i=0; i<R; i++){
    for(int j=0; j<C; j++){
        if(P[i][j].val!='E')
            count+=1;
    }
}
cout << count << endl;
}
    return 0;
}