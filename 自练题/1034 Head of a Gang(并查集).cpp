#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

const int mn = 2e3 + 5;

struct gang{
    string head;
    int num;
};

bool cmp(const gang &a, const gang &b){
    return a.head < b.head;
}

vector<int> fa(mn);
vector<int> sz(mn);
vector<int> time_w(mn);
unordered_map<string, int> name2id;
vector<string> id2name;
int inc_id = 0;

int getid(string s){
    if(!name2id.count(s)){
        name2id[s] = inc_id;
        id2name.pb(s);
        fa[inc_id] = inc_id;
        sz[inc_id] = 1;
        time_w[inc_id] = 0;
        inc_id++;
    }
    return name2id[s];
}

int find(int x){
    if(fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    fa[y] = x;
    sz[x] += sz[y];
}

signed main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        string a, b;
        int t;
        cin >> a >> b >> t;
        int ida = getid(a);
        int idb = getid(b);
        time_w[ida] += t;
        time_w[idb] += t;
        unite(ida, idb);
    }
    unordered_map<int, pair<int, int>> group;
    for(int i = 0; i < inc_id; i++){
        int root = find(i);
        if(!group.count(root)){
            group[root] = {i, sz[root]};
        }else{
            int best = group[root].first;
            if(time_w[best] < time_w[i]) group[root].first = i;
        }
    }
    vector<gang> ans;
    for(auto &p : group){
        int root = p.first;
        int hid = p.second.first;
        int ppnum = p.second.second;
        int sum = 0;
        for(int i = 0; i < inc_id; i++){
            if(find(i) == root) sum += time_w[i];
        }
        sum /= 2;
        if(ppnum > 2 && sum > k){
            ans.pb({id2name[hid], ppnum});
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << ans.size() << endl;
    for(auto &a : ans){
        cout << a.head << " " << a.num << endl;
    }
    return 0;
}