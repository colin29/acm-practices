#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cctype>

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

int main(){
string a;


string line;
while(getline(cin, line)){
	vector<int> e;
	vector<string> d;
	istringstream iss(line);
	string a;
	if(line == ""){
		continue;
	}
	while(iss >> a){
		d.push_back(a);
	}
	

	if(d.size()<3){
		e.push_back(2);
	}else{
		if(*(d.end()-1) != "clap" || *(d.end()-2) != "stomp" || *(d.end()-3) != "clap"){
			e.push_back(2);
		}
	}

	bool hasDip = false;
	bool hasTwirl = false, hasHop =false;
	for(int i=0; i<d.size(); i++){
		if(d[i]=="twirl")
			hasTwirl=true;
		if(d[i]=="hop")
			hasHop=true;
		if(d[i]=="dip")
			hasDip=true;
	}
	if(!hasDip){
		e.push_back(5);
	}
	if(hasTwirl && !hasHop){
		e.push_back(3);
	}

	if(d.size()>=1){
		if(d[0]=="jiggle"){
			e.push_back(4);
		}
	}

	bool hasError1 = false;
	for(int i=0; i<d.size(); i++){
		if(d[i]=="dip"){
			if(i+1<d.size() && d[i+1]=="twirl"){
				continue;
			}
			if(i==0 || i==1 && d[0]!="jiggle"){
				hasError1=true;
				d[i]="DIP";
			}else{
				if(d[i-1]!="jiggle" && d[i-2]!="jiggle"){
					hasError1=true;
					d[i]="DIP";
				}
			}
		}
	}
	if(hasError1){
		e.push_back(1);
	}

	//do error printing out;
	sort(e.begin(), e.end());
	bool capitalize = false;
	if(e.size()==0){
		cout << "form ok:";
	}else if(e.size()==1){
		cout << "form error " << e[0] << ":";
	}else{
		cout << "form errors " << e[0];
		for(int i=1; i<e.size()-1; i++){
			cout << ", " << e[i];
		}
		cout << " and " << *(e.end()-1) << ":";
	}
	for(int i=0; i<d.size(); i++){
		cout << " " << d[i];
	}
	cout << endl;

	}
}