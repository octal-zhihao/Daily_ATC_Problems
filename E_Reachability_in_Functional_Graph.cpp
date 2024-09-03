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
    vector<int> a(n+1), deg(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i], deg[a[i]]++;
    queue<int> q;
    vector<int> stk;
    vector<bool> vis(n+1);
    for(int i=1; i<=n; i++) {
        if(deg[i] == 0) {
            vis[i] = 1;
            q.push(i);
            stk.push_back(i);
        }
    }
    while(q.size()) {
        int u = q.front();
        q.pop();
        int v = a[u];
        deg[v] --;
        if(deg[v] == 0) {
            vis[v] = 1;
            q.push(v);
            stk.push_back(v);
        }
    }

    vector<int> fa(n+1);
    for(int i=1; i<=n; i++)
        fa[i] = i;
    function<int(int)> find = [&](int u) {
        if(fa[u] == u) return u;
        return fa[u] = find(fa[u]);
    };

    for(int i=1; i<=n; i++) {
        if(vis[i]) continue;
        int x = find(i);
        int y = find(a[i]);
        if(x != y) fa[x] = y;
    }
    vector<int> sz(n+1);
    for(int i=1; i<=n; i++) {
        sz[find(i)] ++;
    }
    while(stk.size()) {
        int u = stk.back();
        stk.pop_back();
        sz[u] += sz[find(a[u])];
    }
    ll res = 0;
    for(int i=1; i<=n; i++) {
        res += sz[find(i)];
    }
    cout << endl;
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