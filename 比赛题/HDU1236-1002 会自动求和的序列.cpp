#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#define ull unsigned long long

struct BIT{
    int n;
    vector<ull> c1, c2;
    BIT(int nn): n(nn), c1(nn + 2, 0), c2(nn + 2, 0){}
    void add(int p, ull x){
        for(int i = p; i <= n; i += i & -i){
            c1[i] += x;
            c2[i] += x * p;
        }
    }
    ull query(int p){
        ull res = 0;
        for(int i = p; i; i -= i & -i) res += (p + 1ULL) * c1[i] - c2[i];
        return res;
    }
    void range_add(int l, int r, ull x){
        add(l, x);
        add(r + 1, -x);
    }
    ull range_sum(int l, int r){
        return query(r) - query(l - 1);
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<ull> pre_a(n + 1, 0);
        BIT bit_b(n), bit_c(n);
        for(int i = 1; i <= n; i++){
            ull a, b;
            cin >> a >> b;
            pre_a[i] = pre_a[i - 1] + a;
            bit_b.range_add(i, i, b);
        }
        for(int i = 1; i <= m; i++){
            int cmd;
            cin >> cmd;
            int l, r;
            cin >> l >> r;
            if(cmd == 1){
                ull x;
                cin >> x;
                bit_b.range_add(l, r, x);
                bit_c.range_add(l, r, x * i);
            }else{
                ull sum_a = pre_a[r] - pre_a[l - 1];
                ull sum_b = bit_b.range_sum(l, r);
                ull sum_c = bit_c.range_sum(l, r);
                ull ans = sum_a + sum_b * i - sum_c;
                cout << ans << endl;
            }
        }
    }
    return 0;
}