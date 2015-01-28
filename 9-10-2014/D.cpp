#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>



using namespace std;




int main(){



	int N; string s;
    while(cin >> N && N && getline(cin, s)) {
        getline(cin, s);
        istringstream iss(s);
		string com;
		bool neg = false; //whether the x in "x+b" is negative
		int b = 0; // "x+b/k" or something
        while(iss>>com){ //simulate commands
        	if(com[0]=='r'){
        		//cout<<"enter r"<<endl;
        		int howManyTimes = atoi(com.substr(1).c_str());
        		b = (b+howManyTimes)%N;
        	}else if(com[0] == 'm'){
        		//cout<<"enter m"<<endl;
        		int howManyTimes = atoi(com.substr(1).c_str());
        		if(howManyTimes%2==1){
        			neg=!neg;
        			b=(N-b)%N; //b guranteed to be [0,N)
        		}
        	}else{
        	//cout<<"Error: unrecognized command" <<endl;
        	}
        }
       // cout<<"b: " << b << " neg: " << neg<<endl;
        //we end up with neg true or false, and some integer value of b
        if(!neg){
        	if(b==0){
        		//cout<<"do nothing";
        		cout<<endl; //nothing needs to be done
        	}else{
        		if(b< 2 + N-b){
        			cout<<"r" << b <<endl; //one step solution
        		}else{
        			cout<< "m1 r" << N-b << " m1" << endl;
        		}
        	} 
        }else{
        	if(b==0){
        	cout<<"m1"<<endl;
        	}else{
        		if(b<N-b){
        			cout<<"m1 r" << b <<endl; 
        		}else{
        			cout<< "r" << N-b << " m1" <<endl; //2 step solution
        		}
        	}
        }
    }


}


