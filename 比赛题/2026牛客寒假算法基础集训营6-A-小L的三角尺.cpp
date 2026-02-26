#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n, w;
    cin >> n >> w;

    vector<int> x(n), y(n);
    priority_queue<pair<double, int>> max_heap;
    double ans = 0.0;

    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(y[i] == 0) ans += x[i];
        else{
            double curr = sqrt(x[i] * x[i] + y[i] * y[i]);
            ans += curr;
            double d_curr = sqrt(x[i] * x[i] + (y[i] - 1) * (y[i] - 1));
            double delta = (y[i] * 2.0 - 1) / (curr + d_curr);
            max_heap.emplace(delta, i);
        }
    }

    for(int i = 0; i < w; i++){
        if(max_heap.empty()) break;
        auto [delta, j] = max_heap.top();
        max_heap.pop();
        ans -= delta;
        y[j]--;
        if(y[j] > 0){
            double curr = sqrt(x[j] * x[j] + y[j] * y[j]);
            double d_curr = sqrt(x[j] * x[j] + (y[j] - 1) * (y[j] - 1));
            double new_delta = (y[j] * 2.0 - 1) / (curr + d_curr);
            max_heap.emplace(new_delta, j);
        }
    }

    cout << fixed << setprecision(10) << ans;
    return 0;
}