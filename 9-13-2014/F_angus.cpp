#include <iostream>
#include <cstring>
using namespace std;
 
typedef long long ll;
 
const ll mod = 100003;
 
ll dp[33][33];
int n, k;
string p;
 
ll f(int nn, int kk)
{
    if (dp[nn][kk] != -1)
        return dp[nn][kk];
    if (kk == k)
    {
        ll r = 1;
        for (int i = 0; i < nn; i++)
            r = (r*36)%mod;
        dp[nn][kk] = r;
        return r;
    }
    // if there aren't enough letters left return 0
    // letters left to match: k-kk, nn
    if (k-kk > nn)
    {
        dp[nn][kk] = 0;
        return 0;
    }
    ll s = 0;
    for (int i = 0; i < 26; i++)
    {
        char c = 'a'+i;
        if (c == p[kk])
            s = (s+f(nn-1,kk+1))%mod;
        else
        {
            bool g = false;
            for (int j = 0; j <= kk; j++)
            {
                if (p.substr(j,kk-j)+c == p.substr(0,kk-j+1))
                {
                    s = (s+f(nn-1,kk-j+1))%mod;
                    g = true;
                    break;
                }
            }
            if (!g)
                s = (s+f(nn-1,0))%mod;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        char c = '0'+i;
        if (c == p[kk])
            s = (s+f(nn-1,kk+1))%mod;
        else
        {
            bool g = false;
            for (int j = 0; j <= kk; j++)
            {
                if (p.substr(j,kk-j)+c == p.substr(0,kk-j+1))
                {
                    s = (s+f(nn-1,kk-j+1))%mod;
                    g = true;
                    break;
                }
            }
            if (!g)
                s = (s+f(nn-1,0))%mod;
        }
    }
    dp[nn][kk] = s;
    return s;
}
 
int main()
{
    int t; cin >> t;
    while (t--)
    {
        memset(dp, -1, sizeof dp);
        cin >> n >> p;
        k = p.size();
        cout << f(n,0) << "\n";
    }
    return 0;
}