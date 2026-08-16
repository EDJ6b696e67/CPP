#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
const int INF = 1e18;

void print_v(vector<int> v){
    for(int i = 0; i < v.size(); i++){
        if(i) cout << " ";
        cout << v[i];
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int>> adj(n + 1); // 邻接表
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> even(n + 1, INF); // 最短偶路径
        vector<int> odd(n + 1, INF); // 最短奇路径
        queue<pair<int, int>> q; // <节点编号, 奇偶状态：0=偶 1=奇>
        even[1] = 0; // 起点0，偶
        q.push({1, 0});
        // BFS
        while(!q.empty()){
            auto [u, s] = q.front();
            q.pop();
            int d = (s) ? odd[u] : even[u]; // 当前路径
            for(int v : adj[u]){
                int ns = 1 ^ s; // 奇偶翻转
                int nd = d + 1;
                // 更新奇偶最短路
                if(ns == 0 && nd < even[v]){
                    even[v] = nd;
                    q.push({v, 0});
                } else if(ns == 1 && nd < odd[v]){
                    odd[v] = nd;
                    q.push({v, 1});
                }
            }
        }
        vector<int> ans(n);
        for(int i = 1; i <= n; i++){
            int res = INF;
            // 偶最短路
            if(even[i] != INF){
                int t = (even[i] + k - 1) / k; // 向上取整倍数
                int d = t * k;
                if(k % 2 == 0){
                    // k为偶数
                    res = min(res, d);
                } else {
                    // k为奇数
                    if(d % 2 == 0) res = min(res, d);
                    else res = min(res, d + k);
                }
            }
            // 奇最短路
            if(odd[i] != INF){
                int t = (odd[i] + k - 1) / k;
                int d = t * k;
                if(k % 2 == 1){
                    // k为偶数不可能
                    if(d % 2 == 1) res = min(res, d);
                    else res = min(res, d + k);
                }
            }
            ans[i - 1] = (res >= INF) ? -1 : res;
        }
        print_v(ans);
    }
    return 0;
}