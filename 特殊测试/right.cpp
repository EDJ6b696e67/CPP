#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int MAXN = 200005;

vector<int> adj[MAXN];
vector<int> children[MAXN];
vector<int> depth(MAXN);
vector<int> parent(MAXN);
vector<int> order;

vector<pair<int,int>> node_particles[MAXN]; // (p, person_id)
vector<unordered_map<int,int>> mp;           // p -> person_id
vector<int> ans;

void dfs(int root){
    order.clear();
    stack<int> st;
    st.push(root);
    parent[root] = 0;
    depth[root] = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();
        order.pb(u);
        for(int v : adj[u]){
            if(v == parent[u]) continue;
            parent[v] = u;
            depth[v] = depth[u] + 1;
            children[u].pb(v);
            st.push(v);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        adj[i].clear();
        children[i].clear();
        node_particles[i].clear();
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1);

    mp.assign(n + 1, unordered_map<int,int>());
    ans.assign(m + 1, 0);

    for(int i = 1; i <= m; i++){
        int x, s;
        cin >> x >> s;
        int p = depth[x] + s;
        node_particles[x].pb({p, i});
    }

    reverse(order.begin(), order.end()); // 从深到浅

    for(int u : order){
        unordered_set<int> dead; // 本节点已经因冲突全体消失的 p

        // 1. 合并所有子节点
        for(int v : children[u]){
            if(mp[u].size() < mp[v].size()){
                mp[u].swap(mp[v]); // 启发式合并
            }

            for(auto &kv : mp[v]){
                int p = kv.first;
                int id_v = kv.second;

                if(dead.count(p)){
                    ans[id_v] = 0;
                    continue;
                }

                auto it = mp[u].find(p);
                if(it != mp[u].end()){
                    // 碰撞：两个都消失
                    ans[it->second] = 0;
                    ans[id_v] = 0;
                    mp[u].erase(it);
                    dead.insert(p);
                } else {
                    mp[u][p] = id_v;
                }
            }
            mp[v].clear();
        }

        // 2. 处理出生在 u 的粒子
        for(auto &pr : node_particles[u]){
            int p = pr.first;
            int id = pr.second;

            if(dead.count(p)){
                ans[id] = 0;
                continue;
            }

            auto it = mp[u].find(p);
            if(it != mp[u].end()){
                ans[it->second] = 0;
                ans[id] = 0;
                mp[u].erase(it);
                dead.insert(p);
            } else {
                mp[u][p] = id;
            }
        }

        node_particles[u].clear();
    }

    // 根节点剩余活跃粒子成功逃脱
    for(auto &kv : mp[1]){
        ans[kv.second] = 1;
    }

    for(int i = 1; i <= m; i++){
        cout << ans[i];
    }
    cout << endl;

    return 0;
}