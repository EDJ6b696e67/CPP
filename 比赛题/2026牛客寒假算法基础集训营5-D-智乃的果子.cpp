#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int MOD = 1e9 + 7;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;

signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int c, w;
        cin >> c >> w;
        heap.push({w, c});
    }

    int ans = 0;
    while(!heap.empty()){
        auto [fir_w, fir_c] = heap.top();
        heap.pop();

        if(fir_c >= 2){
            int k = fir_c / 2;
            int cost = (2 * fir_w * k) % MOD;
            ans = (ans + cost) % MOD;

            int new_fir_c = fir_c % 2;
            int new_w = 2 * fir_w;
            int new_c = k;

            if(new_fir_c > 0){
                heap.push({fir_w, new_fir_c});
            }

            heap.push({new_w, new_c});
            continue;
        }

        if(heap.empty()) break;

        auto [sec_w, sec_c] = heap.top();
        heap.pop();

        int cost = (fir_w + sec_w) % MOD;
        ans = (ans + cost) % MOD;

        int new_sec_c = sec_c - 1;
        int new_w = fir_w + sec_w;
        int new_c = 1;

        if(new_sec_c > 0){
            heap.push({sec_w, new_sec_c});
        }

        heap.push({new_w, new_c});
    }

    cout << ans % MOD << endl;

    return 0;
}