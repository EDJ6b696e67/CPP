#include <vector>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int modpow(int a, int b){
    int res = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
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
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    invfact[n] = modpow(fact[n], MOD - 2);
    for(int i = n - 1; i >= 0; i--){
        invfact[i] = (invfact[i + 1] * (i + 1)) % MOD;
    }
}

int combinatorics(int n, int k){
    if(k < 0 || k > n) return 0;
    return (((fact[n] * invfact[k]) % MOD) * invfact[n - k]) % MOD;
}