#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <math.h>
#include <string.h>

const long double EPS = 1e-9;

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> P;
	int a;
	for(int i=0; i<n; i++){
		cin >> a;
		P.push_back(a);
	}
	sort(P.begin(), P.end());


int count =0; //how many  buildings we got
int cost = 0; //how many slices we did.

	int score =0;
	int level =0;
	for(int i=0; i<n;){
		score -= 1;
		level +=1;
		if(P[i]<=level){
			score +=1;
			// cout << P[i] << endl;
			// cout << "score, i: " << score << " " << i << endl;
			if(score>=0){
				score = 0;
				count = i+1;
				cost = level; 
				// cout << "score, count, cost: " << score << " " << count << " " << cost << " " << endl;
			}
			i++;
			level -=1;
			score+=1;
		}else{
			continue; //try increasing the level;
		}
	}

cout << cost + (n-count) << endl;
}