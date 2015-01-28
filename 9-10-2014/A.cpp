#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


bool mySort(const string& s1, const string& s2){
	return s1<s2;
}

int main(){

//sort dictionary (probably a set.)
int n,m;
vector<string> dic;
while(cin>>n){
	string w;
	getline(cin, w);
	dic.clear();

	for (int i = 0; i < n; ++i)
		{
			getline(cin, w);
			dic.push_back(w);
			//cout<<"inserted w: " << w <<endl;
		}	

	cin>>m;
	getline(cin, w);
	for (int i = 0; i < m; ++i)
		{
			getline(cin, w);
			string d;
			bool found = false;
			bool correct = false;
			string gotit;
			int dl, wl;
			 //allowed error
			//cout<<"checking word: " << w <<endl;
			for (int i = 0; i < n; ++i)
			{
				d=dic[i];
				dl=d.length(); wl=w.length();
				bool error = false;
				if(d==w){
					correct = true;
					//cout<<"w, d: " << w << " " << d <<endl;
					cout<<w << " is correct" <<endl;
					break;
				}
				//cout<<"wl, dl: "<< wl << " " << dl <<endl;
				if(abs(dl-wl)>1)
					{continue;}
				if(found){continue;} //don't search for a misspelling if one's been found
				if(wl==dl+1){
					//cout<<"1 over: " << w << " " << d << endl;
					for (int j=0; j<wl; j++){ //up to longer word
						//cout<<"error: " << error <<endl;
						//cout<<"comp: " << w[j] << " " << d[j-error] <<endl;
						if(!(d[j-error]==w[j]))
							if(error){
								break;
							}else{
								error=true;
							}
							if(j-error == dl-1){
							//if we make it to here without breaking:
							//cout<< "1-over match: " << w << " " << d << endl;
							found = true;
							gotit = d;
							break;
						}
					}
					//if(found) break;
				}else if(wl==dl-1){
					//cout<<"1 under: " << w << " " << d << endl;
					for (int j=0; j<dl; j++){ //up to longer word
						//cout<<"error: " << error <<endl;
						//cout<<"comp: " << w[j-error] << " " << d[j] <<endl;
						if(!(w[j-error]==d[j])){
							if(error){
								break;
							}else{
							error=true;
							}
						}
						if(j-error == wl-1){
							//cout<< "1-under match: " << w << " " << d << endl;
							found = true;
							gotit = d;
							break;
						}
					}
					//if(found) break;
				}else{
					//cout<<"lengths are equal: " << w << " " << d<<endl;
					
					for (int j=0; j<dl; j++){ //up to either word
						//cout<<"error: " << error <<endl;
						//cout<<"comp: " << w[j] << " " << d[j] <<endl;
						if(!(w[j]==d[j])){
							if(error){
								break;
							}else{
								if(w[j]==d[j+1] && w[j+1] == d[j])
									j++; //skip the next
								error=true;
							}
						}
						if(j-error == wl-2){
							//cout<< "even-length match: " << w << " " << d << endl;
							found = true;
							gotit = d;
							break;
						}
					}
				}
				//if(found)break;
			}
			if(!correct && found){
				cout<< w << " is a misspelling of " << gotit <<endl;
			}else if(!correct && !found){
				cout<< w << " is unknown" <<endl;
			}
		}	
}

}