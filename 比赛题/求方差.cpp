#include <bits/stdc++.h>
using namespace std;
#define int long long

// 自定义求 __int128 的最大公约数函数
__int128 gcd128(__int128 a, __int128 b) {
    return b == 0 ? a : gcd128(b, a % b);
}

// 将 __int128 转为字符串输出
string toString(__int128 x) {
    if(x == 0) return "0";
    bool neg = x < 0;
    if(neg) x = -x;
    string s;
    while(x) {
        s.push_back('0' + (x % 10));
        x /= 10;
    }
    if(neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

signed main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int u = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        u += a[i];
    }
    __int128 ans = 0;
    for (int x : a){
        __int128 diff = (__int128)n * x - u;
        ans += diff * diff;
    }
    if(ans == 0){
        cout << "0/1" << endl;
        return 0;
    }
    // 分母为 n^3
    __int128 denom = (__int128)n * n * n;
    __int128 g = gcd128(ans, denom);
    ans /= g;
    denom /= g;
    cout << toString(ans) << "/" << toString(denom) << endl;
    return 0;
}