#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int n;
    cin >> n;
    int totalSum = 0, totalXor = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        totalSum += x;
        totalXor ^= x;
    }
    cout << (totalSum - totalXor) << endl;
    return 0;
}