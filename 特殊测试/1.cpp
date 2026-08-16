#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n, maxp;
    cin >> n >> maxp;
    vector<bool> isprime(maxp + 1, true);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i * i <= maxp; i++){
        if(isprime[i]){
            for(int j = i * i; j <= maxp; j += i){
                isprime[j] = false;
            }
        }
    }
    if(n > 1){
        for(int d = (maxp - 2) / (n - 1); d >= 1; d--){
            for(int a = maxp - (n - 1) * d; a >= 2; a--){
                bool flag = true;
                for(int i = 0; i < n; i++){
                    int x = a + i * d;
                    if(!isprime[x]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    for(int i = 0; i < n; i++){
                        if(i) cout << " ";
                        cout << a + i * d;
                    }
                    return 0;
                }
            } 
        }
    }
    for(int i = maxp; i >= 2; i--){
        if(isprime[i]){
            cout << i;
            break;
        }
    }
    return 0;
}