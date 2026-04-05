#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

int cnt = 0;
vector<int> tree;

void recreate_tree(const vector<int> &input, const int& n, const int curr){
    if(curr > n) return;
    recreate_tree(input, n, 2 * curr);
    recreate_tree(input, n, 2 * curr + 1);
    tree[curr - 1] = input[cnt++];
}

signed main(){
    int n;
    cin >> n;
    vector<int> input(n);
    tree.resize(n);
    for(int i = 0; i < n; i++) cin >> input[i];
    recreate_tree(input, n, 1);
    for(int i = 0; i < n; i++){
        if(i) cout << " ";
        cout << tree[i];
    }
    return 0;
}