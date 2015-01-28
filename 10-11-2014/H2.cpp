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

typedef long long int ll;
const long double EPS = 1e-9;

using namespace std;

int main(){

char p[] = {'a', 'b', 'a', 'a', 'a', 'b', 'a'};
//char p[] = {'a', 'b', 'a', 'b', 'a', 'a'};
int m=7;
int b[m];

    int i=0, j=-1;
    b[i]=j;
    while (i<m)
    {
        while (j>=0 && p[i]!=p[j]) 
        {
        	cout << "inside loop: l: " << j << endl;
        	j=b[j];
        }
        cout << " finished loop: j " << j << endl;
        i++; j++;
        cout << "incremented, i, j: " << i << " " << j << endl;
        b[i]=j;
    }


}