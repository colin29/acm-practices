#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <queue>

const long double EPS = 1e-9;

using namespace std;


int main(){
	int t;
	cin >> t;
	while(t--){
		vector<char> sol;
		for (int i = 0; i < 9; ++i)
		{
			char l;
			cin >> l;
		sol.push_back(l);	/* code */
		}
		// for(int c=0; c<3;c++){
		// 	for(int d=0; d<3; d++){
		// 		cout << sol[c*3+d] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		queue<vector<char> > empty;
		queue<vector<char> > Q;	
		swap(Q, empty);
		int count = 0;
		vector<char> start(9, '.');
		vector<char> chosen;
		chosen.clear();
		Q.push(start);
		Q.push(chosen);

		vector<char> cur;
		while(true){
			if(Q.empty()){
				cout<<"error empty queue"<< endl;}
				cur = Q.front();
				Q.pop();
				chosen = Q.front();
				Q.pop();
				// cout<<"current graph"<<endl;
				// for(int c=0; c<3;c++){
				// 	for(int d=0; d<3; d++){
				// 		cout << cur[c*3+d] << " ";
				// 	}
				// 	cout << endl;
				// }
				// for(int j=0; j<chosen.size(); j++){
				// 	cout << chosen[j] << " ";
				// }
				// cout << endl;

				if(cur==sol){
					cout << chosen.size()<<endl;
					break;
				}

				for(char j='0';j<'9';j++){
					if(find(chosen.begin(), chosen.end(), j)==chosen.end()) {
						int b = j-48;
						cur[b]=((cur[b]=='.')?'*':'.');
						if(b-3 >=0){
							cur[b-3]=((cur[b-3]=='.')?'*':'.');
						}
						if(b+3 <=8){
							cur[b+3]=((cur[b+3]=='.')?'*':'.');
						}
						if(b%3 != 0){
							cur[b-1]=((cur[b-1]=='.')?'*':'.');
						}
						if(b%3 != 2){
							cur[b+1]=((cur[b+1]=='.')?'*':'.');
						}
						Q.push(cur);
						chosen.push_back(j);
						Q.push(chosen);
						chosen.pop_back();

						cur[b]=((cur[b]=='.')?'*':'.');  //undo what we did
						if(b-3 >=0){
							cur[b-3]=((cur[b-3]=='.')?'*':'.');
						}
						if(b+3 <=8){
							cur[b+3]=((cur[b+3]=='.')?'*':'.');
						}
						if(b%3 != 0){
							cur[b-1]=((cur[b-1]=='.')?'*':'.');
						}
						if(b%3 != 2){
							cur[b+1]=((cur[b+1]=='.')?'*':'.');
						}
					}
					
					
					
				}


			}
		}
	}