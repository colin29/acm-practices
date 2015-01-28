#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int a, b;
int main(){
	cin >> a >>b;
	int count = 0;
	while(true){
		if(a<=0) break;
		a-=1;
		count+=1;
		if(count%b==0 && count>0)
			a+=1;
		
	}
	cout<<count<<endl;

	return 0;
}