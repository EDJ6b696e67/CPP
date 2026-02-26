#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

int modpow(int a, int b, int MOD){
    int res = 1;
    a %= MOD;
    while(b > 0){
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

bool is_prime(int a){
    if(a <= 3 && a != 1) return true;
    if(a % 2 == 0) return false;
    int d = a - 1;
    int s = 0;
    while(d % 2 == 0){
        d >>= 1;
        s++;
    }

    vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    for(auto it : bases){
        if(it >= a) continue;
        int x = modpow(it, d, a);
        if(x == 1 || x == a - 1) continue;

        bool flag = false;
        for(int i = 0; i < s - 1; i++){
            x = modpow(x, 2, a);
            if(x == a - 1){
                flag = true;
                break;
            }
        }
        if(!flag) return false;
    }
    return true;
}
signed main(){

    int c, d;
    cin >> c >> d;
    int a = min(c, d);
    int b = max(c, d);

    bool found_min = false, found_max = false;
    int minp = -1, maxp = -1;

    // handle prime 2 separately
    if(a <= 2 && 2 <= b){
        found_min = true;
        minp = 2;
        // do not set found_max here; there may be larger primes
    }

    int i = max(a, (int)3);
    if(i % 2 == 0) i++;
    int j = b;
    if(j % 2 == 0) j--;

    while(i <= j){
        if(!found_min){
            if(is_prime(i)){
                minp = i;
                found_min = true;
            }
            i += 2;
        }
        if(!found_max){
            if(is_prime(j)){
                maxp = j;
                found_max = true;
            }
            j -= 2;
        }
        if(found_min && found_max) break;
    }

    // if we found only min (could be 2) and not max, set max = min
    if(found_min && !found_max){
        // maybe we found 2 earlier but no larger prime found
        cout << minp << ' ' << minp;
    } else if(!found_min && found_max){
        cout << maxp << ' ' << maxp;
    } else if(found_min && found_max){
        cout << minp << ' ' << maxp;
    } else {
        cout << "NONE";
    }
    return 0;
}