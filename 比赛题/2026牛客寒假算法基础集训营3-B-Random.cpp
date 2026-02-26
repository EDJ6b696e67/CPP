#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

set<int> primes;

void sieve(int n){
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i <= n; i++){
        if(isPrime[i]){
            for(int j = i * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(isPrime[i]){
            primes.insert(i);
        }
    }
}

signed main(){
    int T;
    cin >> T;
    sieve(31623);
    while(T--){
        int n;
        cin >> n;
        unordered_map<int,int> seen;// key:质因数，value:对应的元素值
        bool found = false;
        vector<int> vals(n);
        for(int i = 0; i < n; ++i) cin >> vals[i];
        for(int v : vals){
            if(found) break;
            int x = v;
            // 用预筛的质数分解x
            if(x == 1) continue;
            for(int p : primes){
                if((long long)p * p > x) break;
                if(x % p == 0){
                    if(seen.count(p)){
                        // 找到符合条件的两个数，输出后终止
                        cout << seen[p] << " " << v << endl;
                        found = true;
                        break;
                    }
                    seen[p] = v;
                    while(x % p == 0) x /= p;
                }
            }
            if(found) break;
            // 处理剩余的大质数（大于√v的质因数）
            if(x > 1){
                int p = x;
                if(seen.count(p)){
                    cout << seen[p] << " " << v << endl;
                    found = true;
                    break;
                }
                seen[p] = v;
            }
        }
        if(!found) cout << -1 << endl;
    }
    return 0;
}