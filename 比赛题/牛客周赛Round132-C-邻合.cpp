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
        vector<int> arr(n);
        vector<bool> changed(n, false);
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            if(arr[i] == 1){
                changed[i] = true;
                cnt++;
            }
        }
        for(int i = 0; i < n - 1; i++){
            if(__gcd(arr[i], arr[i + 1]) == 1){
                if(changed[i] || changed[i + 1]) continue;
                else{
                    changed[i + 1] = true;
                    cnt++;
                    i++;
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}