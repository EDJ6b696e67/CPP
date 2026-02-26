#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> a(n);
        int max_val = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            max_val = max(max_val, a[i]);
        }
        int cnt_max = count(a.begin(), a.end(), max_val);
        string ans(n, '0');
        for (int i = 0; i < n; ++i) {
            if (a[i] < max_val) {
                if (cnt_max % 2 == 0) ans[i] = '1';
            } else {
                if ((cnt_max - 1) % 2 == 0) ans[i] = '1';
            }
        }
        cout << ans << endl;
    }
    return 0;
}