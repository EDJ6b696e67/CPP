#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> realmap(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++) cin >> realmap[i][j];
    }

    vector<vector<int>> cannons_map(n + 2, vector<int>(m + 2, 0));
    int max_val = -1, max_x = 0, max_y = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){

            // 曼哈顿距离判断求和
            int sum = 0;
            for(int dx = -2; dx <= 2; dx++) {
                for(int dy = -2; dy <= 2; dy++) {
                    if(abs(dx) + abs(dy) > 2) continue;
                    int x = i + dx;
                    int y = j + dy;
                    if(x < 1 || x > n || y < 1 || y > m) continue;
                    sum += realmap[x][y];
                }
            }
            cannons_map[i][j] = sum;
            if(cannons_map[i][j] > max_val){
                max_val = cannons_map[i][j];
                max_x = i;
                max_y = j;
            }
        }
    }

    while(q--){
        int x, y;
        int add;
        cin >> x >> y >> add;
        for(int dx = -2; dx <= 2; dx++){
            for(int dy = -2; dy <= 2; dy++){
                if(abs(dx) + abs(dy) > 2) continue;
                int i = x + dx;
                int j = y + dy;
                if(i < 1 || i > n || j < 1 || j > m) continue;
                cannons_map[i][j] += add;
                if(cannons_map[i][j] > max_val){
                    max_val = cannons_map[i][j];
                    max_x = i;
                    max_y = j;
                }
            }
        }
        cout << max_x << ' ' << max_y << endl;
    }

    return 0;
}