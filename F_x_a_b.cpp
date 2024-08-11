#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    ll n;
    cin >> n;
    ll res = sqrtl(n);
    unordered_map<ll, bool> vis;
    for(ll i=2; i*i*i<=n; i++) {
        ll q = sqrt(i);
        if(q*q == i) continue;
        if(vis.count(i)) continue;
        ll t = i*i;
        while(t <= n/i) {
            t *= i;
            ll q = sqrtl(t);
            if(q*q == t) continue;
            if(!vis.count(t)) {
                vis[t] = 1;
                res ++;
            }
        }
    }
    cout << res << endl;
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