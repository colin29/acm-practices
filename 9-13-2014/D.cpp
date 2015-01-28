#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>

const long double EPS = 1e-9;

using namespace std;

bool comp(int r1, int r2){
	int c1 = 0;
	if(!(r1==0)){
		while((r1 & 1) == 0){
			r1 >>= 1; //need = operator!
			c1 +=1;
		}
	}
	int c2=0;
	if(!(r2==0)){
		while((r2 & 1) == 0){
			r2 >>= 1; //need = operator!
			c2 +=1;	
		}
	}
	return c1>c2;
}

void combine(int& r1, int& r2){
	if(r1==r2){
		r1 = r1*2;
		r2 = 0;
	}else{
		int l = r1;
		r1 = abs(r1-r2);
		r2 = min(l, r2)*2;
	}
}

vector<int> r;
int t, s;
int main(){
	int c, d;
	c=5;
	d=9;
	//ifstream cin("cin.txt");
	combine(c, d);
	while(cin>>t){
		for (int i = 0; i < t; ++i)
		{
				r.clear();
				cin>>s;
				for (int j = 0; j < s; ++j)
				{
					int l;
				cin >> l;
				r.push_back(l);
			}
			sort(r.begin(), r.end(), comp);

			while(r.size()>1){

				//cout<< "Stacks: ";
				//cout << "size: " << r.size() << endl;
				cout<< *(r.end()-2) << " " << r.back() <<endl;
				combine(*(r.end()-2), r.back());
				if(r.back()==0){
					r.pop_back();
				}
				sort(r.begin(), r.end(), comp);
			}
					cout<<"0 0"<<endl;
		}
	}


}