#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Jumping{
public:
string ableToGet(int x, int y, int j[]){
double a, b;
a=x;
b=y;
double c;
c= pow(a*a+b*b, 0.5);

vector<int> jump;
for(int i=0;i<(sizeof(j)/sizeof(*j)); i++){
jump.push_back(j[i]);
}
int sum =0;
sort(jump.begin(), jump.end());
for(int i=0; i<jump.size(); i++){
	sum+=jump[i];
	if(c<sum && i==0){
	return "Not able";
	}
	if(c<=sum && jump[i]-c <= sum-jump[i]){
		return "Able";
	}
}
return "Not able";
}

};