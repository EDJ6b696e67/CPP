#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

int n;
vector<int> arr;
vector<int> tree_left_first;

bool is_BST(int p, pair<int, int> range){
    if(p >= n || arr[p] == -1) return true;
    if(arr[p] < range.first || arr[p] > range.second) return false;
    int left = p * 2 + 1, right = p * 2 + 2;
    bool flag1 = is_BST(left, {range.first, arr[p] - 1});
    bool flag2 = is_BST(right, {arr[p], range.second});
    return flag1 && flag2;
}

void l_m_r(int p){
    if(p >= n || arr[p] == -1) return;
    l_m_r(p * 2 + 1);
    tree_left_first.pb(arr[p]);
    l_m_r(p * 2 + 2);
}

signed main(){
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    if(is_BST(0, {0, 100000})) cout << "YES" << endl;
    else cout << "NO" << endl;
    l_m_r(0);
    for(int i = 0; i < tree_left_first.size(); i++){
        if(i != 0) cout << ' ';
        cout << tree_left_first[i];
    }
    return 0;
}