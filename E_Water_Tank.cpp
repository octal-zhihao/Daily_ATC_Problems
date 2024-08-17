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
    vector<ll> h(n+1);
    for(int i=1; i<=n; i++)
        cin >> h[i];
    vector<pll> stk;
    vector<ll> res(n+5);
    res[0] = 1;
    stk.push_back({2e9, 0});
    for(int i=1; i<=n; i++) {
        while(stk.size() && h[i] > stk.back().first) {
            stk.pop_back();
        }
        res[i] = res[stk.back().second] + (i - stk.back().second) * h[i];
        stk.push_back({h[i], i});
        cout << res[i] << " ";
    }
}
int main()
{
    freopen("F:\\浏览器下载\\01_random_03.txt", "r", stdin);
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}