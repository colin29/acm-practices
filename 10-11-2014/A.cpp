#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> //abs
#include <fstream>
#include <numeric>
#include <iomanip>

const long double EPS = 1e-9;

using namespace std;

int main(){
int a, b, c, d;
double A, B;
A=B=0;
cin >> a >> b;
A += a+b;
cin >> a >> b;
A += a+b;
cin >> a >> b;
B += a+b;
cin >> a >> b;
B += a+b;
if(A>B){
cout << "Gunnar" << endl;
}else if(B>A){
cout << "Emma" << endl;
}else{
	cout << "Tie" << endl;
}



}