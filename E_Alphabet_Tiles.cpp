#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 998244353;
struct Combi {
    vector<ll> fac, inv;
    ll mod;
    Combi(int n, ll mod) : mod(mod) {
        fac.resize(n+1);
        inv.resize(n+1);
        fac[0] = 1;
        for(int i=1; i<=n; i++) 
            fac[i] = fac[i-1] * i % mod;
        inv[n] = qmi(fac[n], mod-2);
        for(int i=n-1; i>=0; i--) 
            inv[i] = inv[i+1] * (i+1) % mod;
    }
    ll qmi(ll a, ll b) {
        ll res = 1;
        while(b) {
            if(b & 1) res = res*a%mod;
            a = a*a%mod;
            b >>= 1;
        }
        return res;
    }
    ll C(ll x, ll y) {
        if(x < y) return 0ll;
        return (fac[x] * inv[y] % mod * inv[x-y] % mod);
    }
    ll lucas(ll a, ll b) {
        if (a<mod && b<mod) return C(a, b);
        return C(a%mod, b%mod) * lucas(a / mod, b / mod) % mod;
    }
};
inline void solve()
{
    int k;
    cin >> k;
    vector<int> a(27);
    for(int i=1; i<=26; i++)
        cin >> a[i];
    vector<vector<ll>> dp(27, vector<ll>(k+5));
    for(int i=0; i<=26; i++)
        dp[i][0] = 1;
    Combi comb(k+5, mod);

    for(int i=1; i<=26; i++) {
        for(int j=1; j<=k; j++) {
            dp[i][j] = dp[i-1][j];
            for(int s=1; s<=min(j, a[i]); s++) {
                dp[i][j] += dp[i-1][j-s] * comb.C(j, s) % mod;
                dp[i][j] %= mod;
            }
        }
    }
    ll res = 0;
    for(int i=1; i<=k; i++) {
        res += dp[26][i];
        res %= mod;
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