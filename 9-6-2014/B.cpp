#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

	
//s is starting letter, n is number of digits

const int MAX = 100 + 1;
double DP[MAX][MAX]; //Number of letters, starting letter


void fill (int k, int n){ //warning: k: number of letters in alphabet is not the same a S: start
	for (int i = 0; i < MAX; ++i) //empty or initialize table (shouldn't actually be necceary, but might make debugging easier.)
		for (int j =0; j < MAX; ++j)
			DP[i][j]=0;
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			if(i==0) {
				DP[i][j]=0;
				
			}else if(i==1){
				DP[i][j]=1;
			}else{
			DP[i][j]+= j>=1 ? DP[i-1][j-1] : 0;
			DP[i][j]+= DP[i-1][j];
			DP[i][j]+= j<=k-1 ? DP[i-1][j+1] : 0;
			}	
			DP[i][j]/= (k+1);

			// cout<<DP[i][j]<< " ";
		}
		// cout<<endl;
	}
}
//each input requires a new table: clear it.
//solving the question requires tabled filled from
//[n-->1]["a", "b"...k]
//fill table 

int main(){

//ifstream cin("testInput.txt");
while(!cin.eof()){

	
	// ofstream cout("myOutput.txt");
	int k=0, n=0;
	cin >> k >> n;
	if(k==0 && n==0) break;
	//cout<<"Recieved input: " << k << " " << n <<endl;

	fill(k, n);
	double grandTotal=0;

	for (int i = 0; i <= k; ++i)
	{
		// cout<<DP[n][i] << " ";
		grandTotal += DP[n][i];

	}
	//cout<<endl;
	//cout << "Grand Total is " << grandTotal << endl;
	double answer =  grandTotal*100;

	cout <<std::fixed << setprecision(5) << answer<<endl; //force precison to display the necessary 8 (6+up to 2) digits.






}

	return 0;
}

