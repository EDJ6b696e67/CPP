#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;

int max_in_line(vector<int> &line){
    int max_val = line[0];
    for(int val : line){
        if(val > max_val){
            max_val = val;
        }
    }
    return max_val;
}

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int calculate_length(int x){
    int length = 0;
    while(x){
        length++;
        x /= 10;
    }
    return length;
}

int sum_per_digit(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

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

signed main(){
    
    return 0;
}