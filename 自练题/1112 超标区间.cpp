#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n, t;
    cin >> n >> t;
    vector<int> data(n);
    vector<int> outbreak_data;
    int maxdata = LLONG_MIN;
    for(int i = 0; i < n; i++){
        cin >> data[i];
        if(data[i] > t){
            outbreak_data.pb(i);
        }
        maxdata = max(maxdata, data[i]);
    }
    if(outbreak_data.size() == 0){
        cout << maxdata << endl;
    } else {
        for(int i = 0; i < outbreak_data.size(); i++){
            if(i == 0 || outbreak_data[i] != outbreak_data[i - 1] + 1){
                cout << "[" << outbreak_data[i];
            }
            if(i == outbreak_data.size() - 1 || outbreak_data[i] + 1 != outbreak_data[i + 1]){
                cout << ", " << outbreak_data[i] << "]" << endl;
            }
        }
    }
    return 0;
}