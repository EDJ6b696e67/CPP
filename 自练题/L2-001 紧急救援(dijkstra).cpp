#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int INF = 1e18;

vector<int> special_dijkstra(int n, const vector<int>& cities_rescues, const vector<vector<pair<int, int>>>& adj_list, vector<int>& dist, vector<int>& cnt_shortest_paths, vector<int>& rescues, int start){
    vector<int> pre_path(n, -1);
    dist[start] = 0;
    cnt_shortest_paths[start] = 1;
    rescues[start] = cities_rescues[start];

    vector<bool> visited(n, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    min_heap.emplace(0, start);

    while(!min_heap.empty()){
        auto [d, u] = min_heap.top();
        min_heap.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(auto& edge : adj_list[u]){
            auto [v, w] = edge;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                cnt_shortest_paths[v] = cnt_shortest_paths[u];
                rescues[v] = rescues[u] + cities_rescues[v];
                pre_path[v] = u;
                min_heap.emplace(dist[v], v);
            }else if(dist[v] == dist[u] + w){
                cnt_shortest_paths[v] += cnt_shortest_paths[u];
                if(rescues[v] < rescues[u] + cities_rescues[v]){
                    rescues[v] = rescues[u] + cities_rescues[v];
                    pre_path[v] = u;
                    min_heap.emplace(dist[v], v);
                }
            }
        }
    }
    return pre_path;
}

vector<int> find_re_path(int cur, const vector<int>& pre_path){
    vector<int> re_path;
    while(cur != -1){
        re_path.pb(cur);
        cur = pre_path[cur];
    }
    reverse(re_path.begin(), re_path.end());
    return re_path;
}

signed main(){
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    vector<int> cities_rescues(n);
    for(int i = 0; i < n; i++) cin >> cities_rescues[i];

    vector<vector<pair<int, int>>> adj_list(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].emplace_back(v, w);
        adj_list[v].emplace_back(u, w);
    }

    vector<int> dist(n, INF);
    vector<int> cnt_shortest_paths(n, 0);
    vector<int> rescues(n, 0);

    vector<int> pre_path = special_dijkstra(n, cities_rescues, adj_list, dist, cnt_shortest_paths, rescues, s);
    vector<int> re_path = find_re_path(d, pre_path);

    cout << cnt_shortest_paths[d] << ' ' << rescues[d] << endl;
    for(int i = 0; i < re_path.size(); i++){
        if(i != 0) cout << ' ';
        cout << re_path[i];
    }
    return 0;
}