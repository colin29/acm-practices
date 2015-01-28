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

queue<vector<char>> Q;
int main(){
	int t;
	cin >> t;
	while(t--){
		vector<int> sol;
		for (int i = 0; i < 9; ++i)
		{
			char l;
			cin >> l;
		sol.push_back(l);	/* code */
		}
		int count = 0;
		vector<char> start('-', 9);
		vector<char> chosen;
		Q.push(start);
		Q.push(chosen);
		vector<char> cur;
		while(true){
			if(Q.empty())
				cout<<"error empty queue"<< endl;
			cur = Q.back();
			Q.pop();
			chosen = Q.back();
			Q.pop();

			if(cur==sol){
				cout << chosen.size();
				break;
			}

			for(char i='0';i<'9';i++){
				if(!(find(chosen.first(), chosen.last(), i)==chosen.last())){
					int b = i-48;
						cur[b]=((cur[b]=='-')?'*':'-';
						if(b-3 >=0){
							cur[b-3]=((cur[b-3]=='-')?'*':'-';
						}
						if(b+3 <=8){
							cur[b+3]=((cur[b+3]=='-')?'*':'-';
						}
						if(b%3 != 0){
							cur[b-1]=((cur[b-1]=='-')?'*':'-';
						}
						if(b%3 != 2){
							cur[b+1]=((cur[b+1]=='-')?'*':'-';
						}
					}
					Q.push(cur);
					chosen.push_back(i);
					Q.push(chosen);
					
					chosen.pop(i);
				}


			}
		}
	}