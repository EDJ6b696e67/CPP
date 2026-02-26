#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    set<int> myset;
    set<int> nextset;
    myset.insert(0);
    for(int i = 0; i < n; i++){
        nextset.clear();
        for(auto it : myset){
            int x1 = max(0ll, it - A[i]);
            nextset.insert(x1);
            int x2 = it ^ B[i];
            nextset.insert(x2);
        }
        myset.clear();
        myset = nextset;
    }
    cout << *myset.rbegin();
    return 0;
}