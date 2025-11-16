#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int find_farthest_node(const vector<vector<int>>& tree, int root) {
    int n = (int)tree.size() - 1; // tree 使用 1..n，下标 0 未用
    if (n <= 0) return root;

    vector<bool> visited(n + 1, 0);         // 访问标记，防止重复
    stack<pair<int,int>> st;                // 显式栈： (node, depth)
    st.push({root, 0});
    visited[root] = 1;

    int best_node = root;                   // 当前记录的最远节点
    int max_depth = 0;                      // 当前最大深度（root 深度为 0）

    while (!st.empty()) {
        auto [u, d] = st.top();
        st.pop();

        // 更新最远节点（题目保证唯一，因此遇到更大深度即可替换）
        if (d > max_depth) {
            max_depth = d;
            best_node = u;
        }

        // 将所有未访问的子节点压栈，深度为 d+1
        // 不需要反向压栈保证顺序，因为我们只关心距离，不关心遍历顺序。
        for (int v : tree[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                st.push({v, d + 1});
            }
        }
    }

    return best_node;
}


signed main(){
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);

    for(int i = 1; i <= n; i++){
        int k;
        cin >> k;
        tree[i].reserve(k);
        for(int j = 0; j < k; j++){
            int v;
            cin >> v;
            tree[i].push_back(v);
        }
    }

    cout << find_farthest_node(tree, 1) << endl;
    return 0;
}