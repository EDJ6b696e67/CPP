#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

struct node{
    int value;
    int parent;
    bool visited;
    node(int val, int par, bool vis): value(val), parent(par), visited(vis) {}
};

signed main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        if(n == 1){
            cout << 1 << endl;
            continue;
        }

        // 邻接表
        vector<vector<int>> Adjacency_List(n + 1);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            Adjacency_List[u].pb(v);
            Adjacency_List[v].pb(u);
        }

        // 存储子树大小
        vector<int> tree_size(n + 1, 1);
        stack<node> st_nodes;
        st_nodes.push(node(1, -1, false));

        // 非递归后序遍历计算子树大小
        while(!st_nodes.empty()){
            node current = st_nodes.top();
            st_nodes.pop();

            if(current.visited){
                for(int neighbor : Adjacency_List[current.value]){
                    if(neighbor != current.parent){
                        tree_size[current.value] += tree_size[neighbor];
                    }
                }
            } else {
                st_nodes.push(node(current.value, current.parent, true));
                for(int neighbor : Adjacency_List[current.value]){
                    if(neighbor != current.parent){
                        st_nodes.push(node(neighbor, current.value, false));
                    }
                }
            }
        }

        int cnt = 0;
        for(int i = 1; i <= n; i++){
            bool perfect = true;

            for(int neighbor : Adjacency_List[i]){
                if(tree_size[neighbor] < tree_size[i]){
                    if(tree_size[neighbor] % 2 == 0){
                        perfect = false;
                        break;
                    }
                }
            }
            if(!perfect){
                continue;
            }

            if(tree_size[i] != n && (n - tree_size[i]) % 2 == 0){
                perfect = false;
            }
            
            if(perfect){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}