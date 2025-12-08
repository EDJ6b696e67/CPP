#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        int answer = 0;
        if(a[0] == -1 || a[n - 1] == -1) answer = 0;
        else answer = llabs(a[0] - a[n - 1]);
        cout << answer << endl;

        vector<int> result = a;
        if(result[0] == -1 && a[n - 1] != -1){
            result[0] = a[n - 1];
        }
        if(result[n - 1] == -1 && a[0] != -1){
            result[n - 1] = a[0];
        }
        for(int i = 0; i < n; i++){
            if(i) cout << " ";
            if(result[i] == -1) result[i] = 0;
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}