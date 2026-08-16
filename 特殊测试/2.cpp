#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

int toSec(string t) {
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}

signed main(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        string x, y;
        cin >> x >> y;
        a[i] = {toSec(x), toSec(y)};
    }

    sort(a.begin(), a.end(), [](const pair<int, int>& A, const pair<int, int>& B) {
        if (A.second != B.second) return A.second < B.second;
        return A.first < B.first;
    });

    int ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= last) {
            ans++;
            last = a[i].second;
        }
    }

    cout << ans;
    return 0;
}