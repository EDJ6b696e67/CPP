#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

signed main(){
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.length(); i++){
        string sub = s.substr(i, s.length() - i);
        int num = stoi(sub);
        if(is_prime(num)){
            cout << sub << ' ' << "Yes" << endl;
        }else{
            cout << sub << ' ' << "No" << endl;
            flag = false;
        }
    }
    if(flag){
        cout << "All Prime!" << endl;
    }
    return 0;
}