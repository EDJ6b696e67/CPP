#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int n, k;
    cin >> n >> k;
    int d = __gcd(n, k);
    cout << n / d << endl;
    return 0;
}