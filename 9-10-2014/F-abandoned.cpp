#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){

ifstream cin("testInput.txt");

long N, a, b;
int counter = 0;
vector<int> list;
vector<int> sorted;


while(!cin.eof()){


list.clear();
cin >> N >> a >> b;
if(N==0) break;
//cout << "N: " << N << " a: " << a << " b: " << b << endl;


long curr = 0; //current soldier
int intCurr=0;
//generate the list of the 500000 or so people
// cout<< "curr: " << curr << endl;
counter=0;
while(true){
intCurr = (int) curr;
//cout<< "curr: " << curr << endl;
list.push_back(intCurr);
curr = ((((curr*curr)%N)*a)%N+b)%N; //modulus to stop it from overflowing long


counter += 1;

if(counter>N || counter>1000001)
    break;
}

vector<int> sorted(list);
sort(sorted.begin(), sorted.end());

if(N<20){
    for(int i=0; i< sorted.size(); i++){
        //cout<<sorted[i];
    }
}

vector<int> singled;
for (int i = 0; i < sorted.size(); ++i)
{
    if(i==0){
    singled.push_back(sorted[i]);
    continue;
    }
    if(sorted[i] == singled.back()){
        continue;
    }else{
        singled.push_back(sorted[i]);
    }
}

//cout<<"Size of sorted: " << sorted.size()<<endl;
//cout<<"Size of singled: " << singled.size()<<endl;

vector<int> seen(singled.size(), 0);
for(int i=0; i< singled.size(); ++i){
    //cout<< i << ": " << singled[i] << " ";
    //cout << endl;
}

// for (int i = 0; i < list.size(); ++i)
// {
//     cout << "list: " << i << ": " <<list[i] << endl;
// }

cout<<"Traversing" <<endl;
cout<<"seen.size: " << seen.size()<<endl;
int sizeofLoop;
for (int i = 0; i < list.size(); ++i)
{
    // cout << "-->Searching for: " << i << ": " <<list[i] << endl;

    int s=0, e=seen.size();
    int diff;
    sizeofLoop = 0;

    while(true){ //search from [s, e) --- binary SEARCH
        diff=e-s;
        if(diff==0)
            cout<<"error 0 diff";
        if(diff==1){ //we've found the element in seen

            if(seen[s]==0)
                {seen[s]=i+1;
                     // cout<< "Marked " << list[i] << " as seen." << endl;
                    break;
                } //set i to be the place we saw i, plus 1
            else{
                //we've hit our first duplicate!
                sizeofLoop = i-(seen[s]-1);
                 cout << "found duplicate at: " << i << ", loopSize is: " << sizeofLoop <<endl;
            }
            break;
        }
        
        int pivot = singled[s+diff/2];
        // cout<< "pivot: " << s+diff/2 << ": " << singled[s+diff/2] <<endl;
        if(list[i]>pivot)
        {
            s=s+diff/2 + 1;
            //no change to e;
        }else if(list[i]<pivot){
            //no change to s
            e=s+diff/2;
        }else{
            s=s+diff/2;
            e=s+1;
        }

        // cout<<"Will search s: " << s << " e " << e << endl; 

        
    }
    if(sizeofLoop>0){
        break;
    }
}
cout << "N: " << N << " a: " << a << " b: " << b << endl;
cout << "---->Surviving soldiers: " << N - sizeofLoop <<endl;

}   




}