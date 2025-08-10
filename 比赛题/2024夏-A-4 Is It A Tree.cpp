#include <bits/stdc++.h>
using namespace std;

// 宏定义，用于将 int 替换为 long long，防止大数据溢出
#define int long long
// 使用'\n'代替endl以提高输出效率
#define endl '\n'

/*
 * 程序功能：判断给定有向图是否构成一颗树。
 *
 * 输入说明：
 *  - 第一行输入一个正整数 n，表示节点总数（节点编号从1到n）。
 *  - 随后多行输入表示有向边，每行两个整数 u 和 v，表示从 u 指向 v 的边。
 *  - 重复出现的边只算作一条。
 *  - 当 u 为0时，表示输入结束，该行不处理。
 *
 * 判断准则：
 *  1. 必须只有且仅有一个入度为0的节点，该点为根节点。
 *  2. 边的总数必须正好为 n - 1 。
 *  3. 从根节点通过DFS或BFS必须能遍历所有节点，保证图连通。
 *
 * 输出说明：
 *  - 如果满足树的条件，输出 "yes root"，其中 root 为根节点编号。
 *  - 如果条件不满足，输出 "no k"，其中 k 表示入度为0节点的个数。
 */

signed main(){
    // 提高输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读取节点总数
    int n;
    cin >> n;

    // 邻接表表示图：图的索引从1开始，故大小为 n+1
    vector<vector<int>> graph(n + 1);

    // 用于统计每个节点的入度，初始化为0（索引1到n）
    vector<int> indegree(n + 1, 0);

    // 使用 set 存储边对，用于去重，避免重复边计数多次
    set<pair<int, int>> edges;
    
    // 读取边数据，当遇到 u 为0时结束输入
    int u, v;
    while(cin >> u){
        if(u == 0) break; // 遇到0停止输入
        cin >> v;
        // 如果该边(u, v)未出现过，则插入 edges 集合
        if(edges.insert({u, v}).second){
            // 将边加入邻接表
            graph[u].push_back(v);
            // 累加目标节点入度
            indegree[v]++;
        }
    }
    
    // 统计入度为0的节点个数，并记录唯一的根节点
    int zeroCount = 0, root = -1;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            zeroCount++; 
            root = i;  // 最后一次记录满足条件的节点
        }
    }
    
    // 判断条件1和条件2：
    // 条件1：只有且仅有一个入度为0的节点
    // 条件2：边数必须等于 n - 1
    if(zeroCount != 1 || edges.size() != n - 1){
        cout << "no " << zeroCount;
        return 0;
    }
    
    // 使用深度优先搜索 (DFS) 检查从根节点是否能访问到所有节点
    vector<bool> visited(n + 1, false);
    stack<int> st;
    st.push(root);  // 从根节点开始
    
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        // 如果当前节点已经访问过，则跳过
        if(visited[cur]) continue;
        visited[cur] = true;
        // 将当前节点所有的直接邻居加入栈中
        for(auto nxt : graph[cur]){
            st.push(nxt);
        }
    }
    
    // 遍历所有节点，检查是否有未访问到的节点
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            // 如果存在未访问的节点，说明图不连通，不构成一颗树
            cout << "no " << zeroCount;
            return 0;
        }
    }
    
    // 如果所有条件满足，则输出结果
    cout << "yes " << root;
    return 0;
}