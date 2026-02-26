#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
const int MOD = 998244353;

int modpow(int a, int b){
    int res = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 预处理阶乘和逆元阶乘
vector<int> fact;
vector<int> invfact;

void initialize_factorials(int n){
    fact.resize(n + 1);
    invfact.resize(n + 1);
    fact[0] = 1;
    for(int i = 1; i <= n; i++){
        fact[i] = fact[i - 1] * i % MOD;
    }
    invfact[n] = modpow(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--){
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
}

int combinatorics(int n, int k){
    if(k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

signed main(){
    initialize_factorials(1e6 + 1);

    int T;
    cin >> T;
    while(T--){
        int n, x, t;
        cin >> n >> x >> t;

        int y = n - x;
        int k = t + 1;
        int ans = 0;

        // 情况1：以左开头、左结尾（块数k为奇数）
        if (k % 2 == 1) {
            int a = (k + 1) / 2; // 左盒分成a块
            int b = (k - 1) / 2; // 右盒分成b块
            int c1 = combinatorics(x - 1, a - 1);
            int c2;
            if(b == 0){
                if(y == 0) c2 = 1;
                else c2 = 0;
            }else{
                c2 = combinatorics(y - 1, b - 1);
            }
            ans = (ans + c1 * c2 % MOD) % MOD;
        }
        
        // 情况2：以右开头、右结尾（块数k为奇数）
        if (k % 2 == 1) {
            int a = (k - 1) / 2; // 左盒分成a块
            int b = (k + 1) / 2; // 右盒分成b块
            int c1;
            if(a == 0){
                if(x == 0) c1 = 1;
                else c1 = 0;
            }else{
                c1 = combinatorics(x - 1, a - 1);
            }
            int c2 = combinatorics(y - 1, b - 1);
            ans = (ans + c1 * c2 % MOD) % MOD;
        }
        
        // 情况3：两端不同（块数k为偶数）
        if (k % 2 == 0) {
            int a = k / 2;
            int b = k / 2;
            if (a >= 1 && b >= 1) {
                int c1 = combinatorics(x - 1, a - 1);
                int c2 = combinatorics(y - 1, b - 1);
                ans = (ans + 2 * c1 * c2 % MOD) % MOD;
            }
        }

        cout << ans << endl;
    }
    return 0;
}