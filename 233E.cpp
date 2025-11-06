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
    string x;
    cin >> x;
    int n = x.size();
    vector<ll> a(n);
    for(int i=1; i<=n; i++) {
        a[i-1] = x[i-1] - '0';
    }
    for(int i=1; i<n; i++) {
        a[i] += a[i-1];
    }
    reverse(a.begin(), a.end());
    for(int i=0; i<n-1; i++) {
        a[i+1] += a[i] / 10;
        a[i] %= 10;
    }
    for(int i=n-1; i>=0; i--)
        cout << a[i];

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