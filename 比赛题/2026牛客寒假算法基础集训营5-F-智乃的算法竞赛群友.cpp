#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int T;
    cin >> T;
    while(T--){
        int n, a, b;
        cin >> n >> a >> b;
        int k1 = n / 8;
        int k2 = n / 7;
        vector<int> cand;
        cand.push_back(0);
        cand.push_back(k1);
        if(k1 + 1 <= k2) cand.push_back(k1 + 1);
        cand.push_back(k2);
        int ans = 0;
        for(int k: cand){
            if(k < 0) continue;
            if(k > n / 7) continue;
            int rem = n - 7 * k;
            int y = min(k, rem);
            int td = y + (rem - y) / 2;
            int total = k * a + td * b;
            ans = max(ans, total);
        }
        cout << ans << endl;
    }
    return 0;
}