#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"
#define debug(x) cout<<#x<<"= "<<x<<endl;
#define adebug(a) cout<<#a<<"= "; for(auto x:a) cout<<x<<" "; cout<<endl;
const int mn = 2 * 2e5 + 5;
int tree[mn * 4];
int total[mn];
struct sn{
    int l, r, len;
    bool operator<(const sn &o) const{
        return r < o.r;
    }
};

struct qn{
    int L, R, id;
    bool operator<(const qn &o) const{
        return R < o.R;
    }
};

void update(int n, int l, int r, int p, int v){
    if(l == r){
        tree[n] = max(tree[n], v);
        return;
    }
    int m = (l + r) / 2;
    if(p <= m) update(n * 2, l, m, p, v);
    else update(n * 2 + 1, m + 1, r, p, v);
    tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int query(int n, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return tree[n];
    int m = (l + r) / 2;
    int res = 0;
    if(ql <= m) res = max(res, query(n * 2, l, m, ql, qr));
    if(qr > m) res = max(res, query(n * 2 + 1, m + 1, r, ql, qr));
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<sn> segs(n);
        
        int k = 0;
        for(int i = 0; i < n; i++){
            cin >> segs[i].l >> segs[i].r;
            segs[i].len = segs[i].r - segs[i].l + 1;
            total[k] = segs[i].l;
            k++;
        }
        vector<qn> qs(q);
        for(int i = 0; i < q; i++){
            cin >> qs[i].L >> qs[i].R;
            qs[i].id = i;
            total[k] = qs[i].L;
            k++;
        }
        sort(total, total + k);
        int size = 0;
        for(int i=1; i<=k; i++){
            if(total[size] != total[i]){
                total[++size] = total[i];
            }
        }
        int m = size;
        sort(segs.begin(), segs.end());
        sort(qs.begin(), qs.end());
        memset(tree, 0, sizeof(tree));
        vector<int> ans(q);
        for(int i = 0, j = 0; i < q; i++){
            int cur_R = qs[i].R;
            int cur_L = qs[i].L;
            int cur_id = qs[i].id;
            while(j < n && segs[j].r <= cur_R){
                int p = lower_bound(total, total + m, segs[j].l) - total + 1;
                update(1, 1, m, p, segs[j].len);
                j++;
            }
            int p = lower_bound(total, total + m, cur_L) - total + 1;
            if(p > m) ans[cur_id] = 0;
            else ans[cur_id] = query(1, 1, m, p, m);
        }
        for(int a : ans) cout << a << endl;
    }
    return 0;
}