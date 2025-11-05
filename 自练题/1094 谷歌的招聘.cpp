#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int transform(string s){
    int res = 0;
    for(char c : s){
        res = res * 10 + (c - '0');
    }
    return res;
}

signed main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 0; i < s.size() - k + 1; i++){
        string sub = s.substr(i, k);
        int num = transform(sub);
        if(is_prime(num)){
            cout << sub << endl;
            return 0;
        }
    }
    cout << "404" << endl;
    return 0;
}