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
    vector<pii> g[n+1];
    ll res = 0;
    for(int i=1; i<n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        res += w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    auto bfs = [&](int s) {
        queue<pll> q;
        vector<ll> d(n+1, -1);
        q.push({s, 0});
        d[s] = 0;
        while(!q.empty()) {
            auto [u, tot] = q.front();
            q.pop();
            for(auto [v, w]: g[u]) {
                if(d[v] != -1) continue;
                q.push({v, tot + w});
                d[v] = tot + w;
            }
        }
        return d;
    };
    auto d = bfs(1);
    int p = 1;
    for(int i=1; i<=n; i++) {
        if(d[i] > d[p]) {
            p = i;
        }
    }
    auto d2 = bfs(p);
    ll maxn = 0;
    for(int i=1; i<=n; i++)
        maxn = max(maxn, d2[i]);
    res *= 2;
    res -= maxn;
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