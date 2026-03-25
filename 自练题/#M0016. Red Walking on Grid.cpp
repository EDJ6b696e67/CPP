#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n;
    cin >> n;
    vector<vector<int>> steps(2, vector<int>(n + 1, 0));
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            if(c == 'R') steps[i][j] = 1;
        }
    }
    int max_val = 1;
    for(int i = 1; i <= n; i++){
        if(steps[0][i]) steps[0][i] = steps[0][i - 1] + 1;
        if(steps[1][i]) steps[1][i] = steps[1][i - 1] + 1;
        if(steps[0][i] && steps[1][i]){
            int step0 = steps[0][i];
            int step1 = steps[1][i];
            steps[0][i] = max(steps[0][i], step1 + 1);
            steps[1][i] = max(steps[1][i], step0 + 1);
        }
        max_val = max({steps[0][i], steps[1][i], max_val});
    }
    cout << max_val - 1;
    return 0;
}