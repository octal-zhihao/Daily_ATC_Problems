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
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    ll res = 0;
    for(int k=0; k<=60; k++) {
        vector<int> pre(n+1);
        int o = 1, j = 0;
        for(int i=1; i<=n; i++) {
            int t = (a[i]>>k&1);
            pre[i] = pre[i-1] + t;
            if(pre[i] % 2) {
                j ++;
                if(t) res += max(0, o-1) * (1ll<<k);
                else res += o * (1ll << k);
            } else {
                o ++;
                if(t) res += max(0, j-1) * (1ll<<k);
                else res += j * (1ll << k);
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