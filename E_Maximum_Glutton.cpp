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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n+1), b(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<vector<int>> dp(x+5, vector<int>(n+5, y+1));
    dp[0][0] = 0;
    for(int i=1; i<=n; i++) {
        for(int j=x-a[i]; j>=0; j--) {
            for(int k=0; k<n; k++) {
                if(dp[j][k] >= y) continue;
                dp[j+a[i]][k+1] = min(dp[j][k]+b[i], dp[j+a[i]][k+1]);
            }
        }
    }
    int res = 1;
    for(int i=1; i<=x; i++) {
        for(int k=0; k<n; k++)
        if(dp[i][k] <= y) {
            res = max(res, k+1);
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