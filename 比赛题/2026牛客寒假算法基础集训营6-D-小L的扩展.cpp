#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

static int n, m;

int f(int x, int y){
    return x * m + y;
}

signed main(){
    int a, b;
    cin >> n >> m >> a >> b;
    int N = n * m;
    const int INF = (1ll << 62);

    // release_time[i] 表示格子 i 被蓝色占据到什么时候（到时刻 t 先变白）
    vector<int> release_time(N, 0);
    // dist[i] 表示格子 i 被黑染到的最早时刻(距离)
    vector<int> dist(N, INF);

    vector<pair<int,int>> blacks;
    for(int i = 0; i < a; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        blacks.emplace_back(x, y);
    }

    for(int i = 0; i < b; i++){
        int x, y, t;
        cin >> x >> y >> t;
        x--;
        y--;
        release_time[f(x, y)] = t;
    }

    // Dijkstra算法
    // 时间从 0 开始，黑色从已黑格子每个整数时刻向四周扩散 1 格
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    for(auto &p : blacks){
        int id = f(p.first, p.second);
        dist[id] = 0;
        heap.push({0, id});
    }

    int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while(!heap.empty()){
        auto [d, u] = heap.top();
        heap.pop();
        if(d != dist[u]) continue;
        int ux = u / m, uy = u % m;
        for(int k = 0; k < 4; k++){
            int vx = ux + dx[k], vy = uy + dy[k];
            if(vx < 0 || vx >= n || vy < 0 || vy >= m) continue;
            int v = f(vx, vy);
            int nd = max(d + 1, release_time[v]);
            if(nd < dist[v]){
                dist[v] = nd;
                heap.push({nd, v});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, dist[i]);
    cout<<ans;
    return 0;
}