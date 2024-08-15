#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
class AC_Automaton { //字符串统计数
    struct node {
        int son[26];
        int cnt, nxt, flag, ans;
        node() : cnt(0), nxt(0), flag(0), ans(0) {
            for(int i=0; i<26; i++)
                son[i] = 0;
        }
    } NIL;
    vector<node> tr;
    vector<int> in;
    unordered_map<int, int> num;
    int idx, n;
public:
    AC_Automaton(int n = 1) : n(n), tr(1), idx(0) {}
    void insert(string x, int id) {
        int p = 0;
        for(char c: x) {
            int cur = c - 'a';
            if (! tr[p].son[cur]) {
                tr.push_back(NIL);
                tr[p].son[cur] = ++idx;
            }
            p = tr[p].son[cur];
        }
        tr[p].cnt ++;
        if(!tr[p].flag) tr[p].flag = id;
        num[id] = tr[p].flag;
    }

    void build() {
        queue<int> q;
        for(int i=0; i<26; i++) {
            if(tr[0].son[i]) {
                q.push(tr[0].son[i]);
            } 
        }
        in.assign(tr.size(), 0);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i=0; i<26; i++) {
                int p = tr[u].son[i];
                if(!p) tr[u].son[i] = tr[tr[u].nxt].son[i];
                else {
                    tr[p].nxt = tr[tr[u].nxt].son[i];
                    in[tr[p].nxt] ++;
                    q.push(p);
                }
            }
        }
    }

    int queryNum(string &s) { //询问在文章s中，出现的单词个数
        int res = 0, u = 0;
        for(char c: s) {
            u = tr[u].son[c-'a'];
            int p = u;
            while(p && tr[p].cnt != -1) {
                res += tr[p].cnt;
                tr[p].cnt = -1;
                p = tr[p].nxt;
            }
        }
        return res;
    }

    vector<int> queryAll(string &s) { // 询问每个单词出现的个数
        vector<int> res(n+1);
        queue<int> q;
        int u = 0;
        for(auto c: s) {
            u = tr[u].son[c-'a'];
            tr[u].ans ++;
        }
        for(int i=1; i<=idx; i++) {
            if(in[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            res[tr[u].flag] += tr[u].ans;
            int v = tr[u].nxt;
            in[v] --;
            tr[v].ans += tr[u].ans;
            if(in[v] == 0) q.push(v);
        }
        for(int i=1; i<=n; i++)
            res[i] = res[num[i]];
        return res;
    }

};
inline void solve()
{
    string T;
    cin >> T;
    int n;
    cin >> n;
    string s;
    AC_Automaton AC(n);
    for(int i=1; i<=n; i++) {
        cin >> s;
        AC.insert(s, i);
    }
    AC.build();
    auto res = AC.queryAll(T);
    for(int i=1; i<=n; i++)
        cout << res[i] << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}