#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 998244353;
inline void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    vector<ll> res(n+1);
    set<int> vis;
    for(int p=1; p<=n; p ++) {
        for(int q=p+1; q<=n; q ++) {
            int d = a[q] - a[p];
            if(vis.count(d)) continue;
            vis.insert(d);
            map<pii, ll> dp, f;
            for(int i=1; i<=n; i++) {
                f = dp;
                f[{a[i], 1}] ++;
                for(int j=1; j<i; j++) {
                    if(!dp.count({a[i]-d, j})) break;
                    f[{a[i], j+1}] += dp[{a[i]-d, j}];
                    f[{a[i], j+1}] %= mod;
                }
                dp = f;
            }
            for(auto [x, y]: dp) {
                res[x.second] += y;
                res[x.second] %= mod;
            }
        }
    }
    res[1] = n;
    for(int i=1; i<=n; i++)
        cout << res[i] << " ";
    
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}