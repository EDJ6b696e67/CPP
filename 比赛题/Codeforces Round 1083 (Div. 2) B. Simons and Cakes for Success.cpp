#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// 质因数分解并计算所有不同质因数的乘积
int solve(int n) {
    if (n == 1) return 1; // 特殊情况：n=1时无质因数
    int ans = 1;
    // 先试除2
    if (n % 2 == 0) {
        ans *= 2;
        while (n % 2 == 0) {
            n /= 2;
        }
    }
    // 再试除奇数，从3开始，到sqrt(n)为止
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            ans *= i;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    // 如果最后剩下的数大于1，说明它本身是质数
    if (n > 1) {
        ans *= n;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false); // 加速cin/cout
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}