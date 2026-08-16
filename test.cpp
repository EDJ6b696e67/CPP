#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
vector<int> kids[MAXN];
vector<int> depth(MAXN);
vector<int> parent(MAXN);
vector<int> order;
vector<pair<int, int>> nodes_p[MAXN];
vector<unordered_map<int, int>> mp;
vector<int> ans;

void dfs(int r){
    order.clear();
    stack<int> s;
    s.push(r);
    parent[r] = 0;
    depth[r] = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        order.pb(u);
        for(int v : adj[u]){
            if(v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            kids[u].pb(v);
            s.push(v);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        adj[i].clear();
        kids[i].clear();
        nodes_p[i].clear();
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    mp.assign(n + 1, unordered_map<int, int>());
    ans.assign(m + 1, 0);
    for(int i = 1; i <= m; i++){
        int x, s;
        cin >> x >> s;
        int p = depth[x] + s;
        nodes_p[x].pb({p, i});
    }
    reverse(order.begin(), order.end());
    for(int u : order){
        unordered_set<int> dead;
        for(int v : kids[u]){
            if(mp[u].size() < mp[v].size()) mp[u].swap(mp[v]);
            for(auto [p, i] : mp[v]){
                if(dead.count(p)){
                    ans[i] = 0;
                    continue;
                }
                auto k = mp[u].find(p);
                if(k != mp[u].end()){
                    ans[k -> second] = 0;
                    ans[i] = 0;
                    mp[u].erase(k);
                    dead.insert(p);
                }else mp[u][p] = i;
            }
            mp[v].clear();
        }
        for(auto [p, i] : nodes_p[u]){
            if(dead.count(p)){
                ans[i] = 0;
                continue;
            }
            auto k = mp[u].find(p);
            if(k != mp[u].end()){
                ans[k -> second] = 0;
                ans[i] = 0;
                mp[u].erase(k);
                dead.insert(p);
            }else mp[u][p] = i;
        }
        nodes_p[u].clear();
    }
    for(auto k : mp[1]) ans[k.second] = 1;
    for(int i = 1; i <= m; i++) cout << ans[i];
    return 0;
}