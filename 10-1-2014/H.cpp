#include <string>
#include <fstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

typedef long double ld;
typedef long long int ll;
typedef pair<double, double> dd;
const ld EPS = 1e-9;

int main(){


    int n, k;
    while( cin >> n >>k && n){
        int map[2*n];
        for(int i=0; i<2*n; i++){
            cin >> map[i];
        }
        int DP [2*n][k+1]; //starting from sqaure n, needing to block off k more starting from that row.
        memset(DP, 0, sizeof DP);

        for(int i=0; i<=k; i++){
            for(int j=0; j<2*n; j++){
                if(i==0){
                    if(j/2 == 0){
                        DP[j][i] = map[0] + map [1];
                        continue;
                    }else{
                        DP[j][i] = DP[j/2*2-2][0] + map[j/2*2] + map[j/2*2+1];
                        continue;
                    }
                }
                if(j/2 == 0){
                    if(i==1){
                        DP[j][i] = map[j];
                    }else{
                        DP[j][i]= -9999999;
                    }
                    continue;
                }
                DP[j][i] = max(DP[j-2][i-1] + map[j], map[j/2*2] + map[j/2*2+1] + max(DP[j/2*2-2][i], DP[j/2*2-1][i]));
            }            
            
        }
        // for(int i=0; i<=k; i++){
        //     for(int j=0; j<2*n; j++){
        //     cout << DP[j][i] << " ";
        //     if(j%2==1)
        //         cout << endl;
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        cout << max(DP[2*n-1][k], DP[2*n-2][k]) << endl;


    }

    return 0;
}