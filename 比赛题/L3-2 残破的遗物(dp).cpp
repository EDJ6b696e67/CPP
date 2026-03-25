#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    string re_s(s.rbegin(), s.rend());
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i - 1] == re_s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int ans = n - dp[n][n];
    cout << ans;
    return 0;
}