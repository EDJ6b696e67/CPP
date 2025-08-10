#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // 加快输入输出操作，避免同步C语言的IO，关闭输入输出刷新提升性能
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 输入顶点数和边数
    int n, m;
    cin >> n >> m;
    
    // 使用邻接表存储无向图，索引从1到n，因此创建 n+1 的大小
    vector<vector<int>> graph(n+1);
    
    // 读入 m 条边，每条边连接两个顶点 u 和 v
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // 无向图，双向加入邻接表
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 输入测试用例数量，每个测试用例对应一个顶点集合，需要判断该集合是否为主集
    int K;
    cin >> K;
    
    // 循环处理每个顶点集合
    while(K--){
        int k;
        cin >> k;
        // inSet数组记录当前集合中的顶点，初始化为false
        vector<bool> inSet(n+1, false);
        // setVertices用来保存集合中的所有顶点编号（可选，用于其他用途）
        vector<int> setVertices(k);
        
        // 读入集合中每个顶点，并更新 inSet 数组
        for (int i = 0; i < k; i++){
            cin >> setVertices[i];
            inSet[setVertices[i]] = true;
        }
        
        // 初始化标志变量dominant为true，假设当前集合为主集
        bool dominant = true;
        
        // 遍历图中所有顶点
        for (int i = 1; i <= n && dominant; i++){
            // 如果当前顶点不在集合中
            if (!inSet[i]){
                bool covered = false;
                // 遍历该顶点的邻接点，检查是否至少有一个邻接点在集合中
                for (int neighbor : graph[i]){
                    if (inSet[neighbor]){
                        covered = true;
                        break;
                    }
                }
                // 如果当前顶点不在集合中且也没有邻接点在集合中，则不是主集
                if (!covered) {
                    dominant = false;
                    break;
                }
            }
        }
        // 输出判断结果，yes表示是主集，no表示不是主集
        cout << (dominant ? "yes" : "no") << "\n";
    }