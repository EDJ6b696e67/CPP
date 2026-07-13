#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

vector<int> parent(10005);

int dsu_find(int x){
    while(parent[x] != x) x = parent[x];
    return x;
}

void dsu_union(int a, int b){
    a = dsu_find(a);
    b = dsu_find(b);
    if(a != b) parent[a] = b;
}

signed main(){
    for(int i = 0; i < 10005; i++) parent[i] = i;
    int n;
    cin >> n;
    set<int> myset;
    while(n--){
        int k;
        cin >> k;
        int prev_x;
        for(int i = 0; i < k; i++){
            int x;
            cin >> x;
            myset.insert(x);
            if(i > 0) dsu_union(prev_x, x);
            prev_x = x;
        }
    }
    cout << myset.size() << " ";
    vector<bool> visited(10005, false);
    int cnt = 0;
    for(int x : myset){
        int root = dsu_find(x);
        parent[x] = root;
        if(!visited[root]){
            visited[root] = true;
            cnt++;
        }
    }
    cout << cnt << endl;
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(parent[a] == parent[b]) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}