#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

struct tree{
    int unit_num = 1;
    vector<int> kids;
};

void tree_calcu(int head, vector<tree>& a){
    for(auto it : a[head].kids){
        tree_calcu(it, a);
    }
    for(auto it : a[head].kids){
        a[head].unit_num += a[it].unit_num;
    }
}

signed main(){
    int n;
    cin >> n;
    vector<tree> amy(n + 1);
    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        amy[x].kids.pb(i);
    }
    tree_calcu(1, amy);
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        cout << amy[x].unit_num << endl;
    }
    return 0;
}