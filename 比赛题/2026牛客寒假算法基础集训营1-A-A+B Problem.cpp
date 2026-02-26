#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#define MOD 998244353
#define max_c 2026

vector<int> percent_of_leds(7);
vector<int> percent_of_digits(10);

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

void initalize_percent_of_digits(){
    percent_of_digits[0] = percent_of_leds[0] * percent_of_leds[1] % MOD * percent_of_leds[2] % MOD * percent_of_leds[4] % MOD * percent_of_leds[5] % MOD * percent_of_leds[6] % MOD * (1 - percent_of_leds[3] + MOD) % MOD;
    percent_of_digits[1] = percent_of_leds[2] * percent_of_leds[5] % MOD * (1 - percent_of_leds[0] + MOD) % MOD * (1 - percent_of_leds[1] + MOD) % MOD * (1 - percent_of_leds[3] + MOD) % MOD * (1 - percent_of_leds[4] + MOD) % MOD * (1 - percent_of_leds[6] + MOD) % MOD;
    percent_of_digits[2] = percent_of_leds[0] * percent_of_leds[2] % MOD * percent_of_leds[3] % MOD * percent_of_leds[4] % MOD * percent_of_leds[6] % MOD * (1 - percent_of_leds[1] + MOD) % MOD * (1 - percent_of_leds[5] + MOD) % MOD;
    percent_of_digits[3] = percent_of_leds[0] * percent_of_leds[2] % MOD * percent_of_leds[3] % MOD * percent_of_leds[5] % MOD * percent_of_leds[6] % MOD * (1 - percent_of_leds[1] + MOD) % MOD * (1 - percent_of_leds[4] + MOD) % MOD;
    percent_of_digits[4] = percent_of_leds[1] * percent_of_leds[2] % MOD * percent_of_leds[3] % MOD * percent_of_leds[5] % MOD * (1 - percent_of_leds[0] + MOD) % MOD * (1 - percent_of_leds[4] + MOD) % MOD * (1 - percent_of_leds[6] + MOD) % MOD;
    percent_of_digits[5] = percent_of_leds[0] * percent_of_leds[1] % MOD * percent_of_leds[3] % MOD * percent_of_leds[5] % MOD * percent_of_leds[6] % MOD * (1 - percent_of_leds[2] + MOD) % MOD * (1 - percent_of_leds[4] + MOD) % MOD;
    percent_of_digits[6] = percent_of_leds[0] * percent_of_leds[1] % MOD * percent_of_leds[3] % MOD * percent_of_leds[4] % MOD * percent_of_leds[5] % MOD * percent_of_leds[6] % MOD * (1 - percent_of_leds[2] + MOD) % MOD;
    percent_of_digits[7] = percent_of_leds[0] * percent_of_leds[2] % MOD * percent_of_leds[5] % MOD * (1 - percent_of_leds[1] + MOD) % MOD * (1 - percent_of_leds[3] + MOD) % MOD * (1 - percent_of_leds[4] + MOD) % MOD * (1 - percent_of_leds[6] + MOD) % MOD;
    percent_of_digits[8] = percent_of_leds[0] * percent_of_leds[1] % MOD * percent_of_leds[2] % MOD * percent_of_leds[3] % MOD * percent_of_leds[4] % MOD * percent_of_leds[5] % MOD * percent_of_leds[6] % MOD;
    percent_of_digits[9] = percent_of_leds[0] * percent_of_leds[1] % MOD * percent_of_leds[2] % MOD * percent_of_leds[3] % MOD * percent_of_leds[5] % MOD * percent_of_leds[6] % MOD * (1 - percent_of_leds[4] + MOD) % MOD;
}

int calcu_per(int num){
    int per = 1;
    for(int i = 0; i < 4; i++){
        int digit = num % 10;
        num /= 10;
        per = (per * percent_of_digits[digit]) % MOD;
    }
    return per;
}

signed main(){
    int T;
    cin >> T;
    int qpow100 = modpow(100, MOD - 2);
    while(T--){
        int C;
        cin >> C;
        for(int i = 0; i < 7; i++){
            int per;
            cin >> per;
            percent_of_leds[i] = (per * qpow100) % MOD;
        }
        initalize_percent_of_digits();
        int A, B;
        int per_of_A, per_of_B;
        int per_of_C;
        int ans = 0;
        for(A = 0; A <= C; A++){
            B = C - A;
            per_of_A = calcu_per(A);
            per_of_B = calcu_per(B);
            per_of_C = (per_of_A * per_of_B) % MOD;
            ans = (ans + per_of_C) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}