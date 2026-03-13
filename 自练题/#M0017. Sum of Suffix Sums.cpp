#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int MOD = 1e9 + 7;

signed main(){
    int q;
    cin >> q;

    vector<pair<int, int>> simulate_stack;
    int sum = 0;

    while(q--){
        int t, v;
        cin >> t >> v;
        for(int i = 0; i < t; i++){
            auto [val, cnt] = simulate_stack.back();
            simulate_stack.pop_back();
            sum = (sum - val * cnt % MOD + MOD) % MOD;
        }
        int val = v % MOD;
        int cnt = simulate_stack.size() + 1;
        simulate_stack.emplace_back(val, cnt);
        sum = (sum + val * cnt % MOD) % MOD;
        cout << sum << endl;
    }
    return 0;
}