#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int maxsize = 20005;

vector<vector<int>> adj(maxsize);
vector<int> treesize(maxsize);
vector<int> dp(maxsize);
vector<int> ans(maxsize);
int n;

void calcu_childtree(int u, int k){
    treesize[u] = 1;
    dp[u] = 0;
    for(int v : adj[u]){
        if(v != k){
            calcu_childtree(v, u);
            treesize[u] += treesize[v];
            dp[u] += dp[v] + treesize[v];
        }
    }
}

void calcu_dis(int u, int k){
    for(int v : adj[u]){
        if(v != k){
            ans[v] = ans[u] - treesize[v] + (n - treesize[v]);
            calcu_dis(v, u);
        }
    }
}

signed main(){

    cin >> n;
    if(n == 1){
        cout << "1 0";
        return 0;
    }

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    calcu_childtree(1, 0);

    ans[1] = dp[1];
    calcu_dis(1, 0);

    int min_val = 1e9;
    int min_node = 1;
    for(int i = 1; i < n; i++){
        if(ans[i] < min_val){
            min_val = ans[i];
            min_node = i;
        }
    }

    cout << min_node << ' ' << min_val;
    return 0;
}