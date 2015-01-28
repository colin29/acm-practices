#include <bits/stdc++.h>
 
using namespace std;
 
int arr[1000005];
int main() {
    int t; cin >> t;
    while (t--) {
        int n, sum = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
 
        int ans = 0, maxdel = 0, mindel = 0;
        for (int i = 0; i < n; i++) {
            maxdel = max(maxdel+arr[i], arr[i]);
            cout << "maxdel: " << maxdel << endl;
            mindel = min(mindel+arr[i], arr[i]);
            ans = max(ans, max(maxdel, sum-mindel));
        }
        cout << ans << endl;
    }
    return 0;
}