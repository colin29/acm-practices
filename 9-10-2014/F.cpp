#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

typedef long long int ll;
typedef pair<ll, int> coord;

struct comp{
bool operator()(const coord &c1, const coord &c2){
    return (c1.first<c2.first);
}
};

int main(){


//ifstream cin("testInput.txt");



ll N=0;
ll a, b;
while(cin>>N && N!=0 && cin>>a && cin>>b){
//  cout<<"N, a, b: " << N <<" " << a << " " << b << endl;

set<coord, comp> soldiers;

ll v=0;
int loopSize=-1;
for(int i=0; i<1000001; i++){

    if(i!=0){
        v=(((((v*v)%N)*a)%N)+b)%N;
    }
    pair<set<coord>::iterator, bool>  ret;  
    ret = soldiers.insert(coord(v, i));
    if(ret.second == false){ //if element already existed
        //perform final calculations:
        loopSize = i - (*ret.first).second;
        break;
    }

    
}
cout<<N-loopSize<<endl;

}   




}