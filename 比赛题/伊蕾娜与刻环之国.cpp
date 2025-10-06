#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int n, k;
    cin >> n >> k;
    //求最大公约数
    int d = __gcd(n, k);
    //约分
    cout << n / d << endl;
    return 0;
}