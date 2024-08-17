#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
const int mod = 998244353;
ll qmi(ll a, ll b, ll mod)
{
	ll res = 1;
	while(b) {
		if(b & 1) res = res*a%mod;
		a = a*a%mod;
		b >>= 1;
	}
	return res;
}
inline void solve()
{
    ll n, k;
    cin >> n >> k;
    //i-1在第一个位置(n^2-(n-1)*2)/(n^2)
    ll p0 = (n*n - (n-1)*2) % mod * qmi(n*n%mod, mod-2, mod) % mod;
    //i-1不在第一个位置2/(n^2)
    ll p1 = 2 * qmi(n*n%mod, mod-2, mod) % mod;
    vector<ll> dp(k+5);
    dp[0] = 1;
    for(int i=1; i<=k; i++) {
        dp[i] = (dp[i-1] * p0 % mod + (1-dp[i-1]+mod) * p1 % mod) % mod;
    }
    //结束时在1的概率
    ll ans = dp[k];
    //结束时在2~n的概率
    ans += ((n+2)*(n-1)/2) % mod * qmi(n-1, mod-2, mod) % mod * (1-dp[k] + mod) % mod;
    ans %= mod;
    cout << ans << endl;
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