#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int INF = 1e18;

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INF));
    vector<bool> vised(n + 1, false);
    vector<int> vishis;
    vishis.pb(0);
    vised[0] = true;
    for (int i = 0; i < n + 1; i++) matrix[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int pos1, pos2, q;
        cin >> pos1 >> pos2 >> q;
        matrix[pos1][pos2] = q;
        matrix[pos2][pos1] = q;
    }
    //Dijkstra
    int pos = 0;
    int ans = 0;
    while (true){
        vector<int> dist(n + 1,INF);
        dist[pos] = 0;
        vector<bool> dvis(n + 1,false);

        for (int i = 0 ; i < n + 1 ; i++) {
            int u = -1;
            int mn = INF;
            for (int j = 0 ; j < n + 1 ; j ++) {
                if (!dvis[j] && dist[j] < mn) {
                    mn = dist[j];
                    u = j;
                }
            }
            if (u == -1) {
                break;
            }
            dvis[u] = true;
            for (int v = 0 ; v < n + 1 ; v++) {
                if (!dvis[v] && matrix[u][v] != INF) {
                    dist[v] = min(dist[v],dist[u] + matrix[u][v]);
                }
            }
        }
        int next = -1;
        for (int i = 1; i <= n; i++) {
            if (!vised[i] && dist[i] != INF) {
                if (next == -1 || dist[i] < dist[next] || (dist[i] == dist[next] && i < next)) {
                    next = i;
                }
            }
        }
        if (next == -1) {
            break;
        }
        vishis.pb(next);
        vised[next] = true;
        ans += dist[next];
        pos = next;
    }
    bool hasnotvis = false;
    for (int i = 0 ; i < n + 1 ; i++) {
        if (!vised[i]) {
            hasnotvis = true;
        }
    }
    if (!hasnotvis) {
        int flag = 0;
        for (auto &x : vishis) {
            if (flag != 0) {
                cout << ' ';
            }
            cout << x;
            flag++;
        }
        cout << endl;
        cout << ans;
    }else {
        int flag = 0;
        for (auto &x : vishis) {
            if (flag != 0) {
                cout << ' ';
            }
            cout << x;
            flag++;
        }
        cout << endl;
        flag = 0;
        for (int i = 1; i <= n; i++) {
            if (!vised[i]) {
                if (flag != 0) {
                    cout << ' ';
                }
                cout << i;
                flag++;
            }
        }
    }
    return 0;
}