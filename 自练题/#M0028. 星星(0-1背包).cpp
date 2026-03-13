#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int INF = 1e10;

signed main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<vector<int>> cost(n, vector<int>(4));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++) cin >> cost[i][j];
        }

        vector<int> dp(k + 1, INF);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = min(k, (i + 1) * 4); j >= 0; j--){
                if(dp[j] == INF) continue;
                if(j + 1 <= k){
                    dp[j + 1] = min(dp[j + 1], dp[j] + cost[i][0]);
                }
                if(j + 2 <= k){
                    dp[j + 2] = min(dp[j + 2], dp[j] + cost[i][1]);
                }
                if(j + 3 <= k){
                    dp[j + 3] = min(dp[j + 3], dp[j] + cost[i][2]);
                }
                if(j + 4 <= k){
                    dp[j + 4] = min(dp[j + 4], dp[j] + cost[i][3]);
                }
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}