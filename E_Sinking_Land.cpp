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
    int n, m, y;
    cin >> n >> m >> y;
    vector<vector<int>> a(n+5, vector<int>(m+5));
    for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
        cin >> a[i][j];
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> hp;
    vector<vector<bool>> vis(n+5, vector<bool>(m+5));
    vector<vector<bool>> isin(n+5, vector<bool>(m+5));
    for(int i=1; i<=n; i++) {
        hp.push({a[i][1], i, 1});
        isin[i][1] = 1;
        hp.push({a[i][m], i, m});
        isin[i][m] = 1;
    }
    for(int j=1; j<=m; j++) {
        hp.push({a[1][j], 1, j});
        isin[1][j] = 1;
        hp.push({a[n][j], n, j});
        isin[n][j] = 1;
    }
    int tot = n*m;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i=1; i<=y; i++) {
        while(!hp.empty()) {
            auto [h, sx, sy] = hp.top();
            if(h > i) break;
            hp.pop();
            if(vis[sx][sy])
                continue;
            queue<pii> q;
            q.push({sx, sy});
            vis[sx][sy] = 1;
            tot --;
            while(!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for(int j=0; j<4; j++) {
                    int xx = x + dx[j];
                    int yy = y + dy[j];
                    if(vis[xx][yy] || xx < 1 || yy < 1 || xx > n || yy > m) continue;
                    if(a[xx][yy] <= i) {
                        q.push({xx, yy});
                        vis[xx][yy] = 1;
                        tot --;
                    } else {
                        if(!isin[xx][yy])
                            hp.push({a[xx][yy], xx, yy});
                    }
                }
            }
        }
        cout << tot << endl;
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