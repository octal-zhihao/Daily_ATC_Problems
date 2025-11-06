#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
struct node{
    ll x;
    ll y;
    friend bool operator<(node a,node b) {
        ll ta = a.x * ((a.y+1)*(a.y+1) - a.y*a.y);
        ll tb = b.x * ((b.y+1)*(b.y+1) - b.y*b.y);
        return ta > tb;
    }
};
priority_queue<node> q;
inline void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a.begin()+1, a.end());
    q.push({a[1], 1});
    q.push({a[2], 1});
    ll res = 0;
    res += a[1] + a[2];
    for(int i=3; i<=n; i++) {
        auto [w, d] = q.top();
        q.pop();
        res += w * ((d+1)*(d+1) - d*d);
        res += a[i];
        q.push({a[i], 1});
        q.push({w, d+1});
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