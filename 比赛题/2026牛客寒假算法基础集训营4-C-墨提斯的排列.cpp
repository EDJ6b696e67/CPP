#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

int pow_2(int n){
    int res = 1;
    for(int i = 0; i < n; i++){
        res <<= 1;
    }
    return res;
}

signed main(){
    int n;
    cin >> n;
    vector<int> pow_of_2s(n);
    for(int i = 0; i < n; i++){
        pow_of_2s[i] = pow_2(i);
    }
    int ans = 0;
    for(int i = 0; i < pow_2(n); i++){
        if(i != 0){
            cout << ' ';
            if(i % 2 == 1){
                ans ^= 1;
            }else{
                for(int j = n - 1; j > 0; j--){
                    if(i % pow_of_2s[j] == 0){
                        ans ^= pow_of_2s[j];
                        break;
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}