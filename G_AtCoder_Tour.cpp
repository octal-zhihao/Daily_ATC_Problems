#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int N = 55;
ll dp[N][N][N*N];

inline void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int sx, sy;
    cin >> sx >> sy;
    vector<vector<ll>> a(n+5, vector<ll>(m+5));
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
        cin >> a[i][j];
    memset(dp, -0x3f, sizeof dp);
    vector<int> dx = {0, 0, 1, 0, -1};
    vector<int> dy = {0, 1, 0, -1, 0};
    dp[sx][sy][0] = 0;
    for(int s=1; s<=n*m; s++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                for(int t=0; t<5; t++) {
                    int x = i + dx[t];
                    int y = j + dy[t];
                    if(x < 1 || y < 1 || x > n || y > m)
                        continue;
                    dp[i][j][s] = max(dp[i][j][s], dp[x][y][s-1] + a[i][j]);
                }
            }
        }
    }

    if(k <= n*m) {
        ll res = 0;
        for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            res = max(res, dp[i][j][k]);
        cout << res << endl;
    } else {
        ll res = 0;
        for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            ll maxv = 0;
            for(int t=0; t<5; t++) {
                int x = i + dx[t];
                int y = j + dy[t];
                if(x < 1 || y < 1 || x > n || y > m)
                    continue;
                maxv = max(maxv, a[x][y]);
            }
            ll t = dp[i][j][n*m];
            t += (k-n*m)/2 * (maxv + a[i][j]);
            t += (k-n*m)%2 * maxv;
            res = max(res, t);
        }
        cout << res << endl;
    }
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