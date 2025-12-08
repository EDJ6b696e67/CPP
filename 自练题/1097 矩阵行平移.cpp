#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int>> a(n, vector<int>(n + k, 0));
    int k_cnt = 1;
    for(int i = 0; i < n; i++){
        if(k_cnt > k) k_cnt = 1;
        if(i%2 != 0){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
            }
        }else{
            for(int j = 0; j < k_cnt; j++){
                a[i][j] = x;
            }
            for(int j = k_cnt; j < n + k_cnt; j++){
                cin >> a[i][j];
            }
            k_cnt++;
        }
    }
    vector<int> sum(n, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            sum[i] += a[j][i];
        }
    }
    for(int i = 0; i < n; i++){
        cout << sum[i];
        if(i != n - 1) cout << " ";
    }
    return 0;
}