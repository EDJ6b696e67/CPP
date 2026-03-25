#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

bool check_bst(const vector<int>& prev_sequence, vector<int>& post_sequence, int left, int right, bool is_mirror){
    if(left > right) return true;
    int root = prev_sequence[left];
    if(left == right){
        post_sequence.pb(root);
        return true;
    }
    int mid = left + 1;
    if(!is_mirror){
        while(mid <= right && prev_sequence[mid] < root){
            mid++;
        }
        for(int i = mid; i <= right; i++){
            if(prev_sequence[i] < root) return false;
        }
    }else{
        while(mid <= right && prev_sequence[mid] >= root){
            mid++;
        }
        for(int i = mid; i <= right; i++){
            if(prev_sequence[i] >= root) return false;
        }
    }
    bool left_valid = check_bst(prev_sequence, post_sequence, left + 1, mid - 1, is_mirror);
    bool right_valid = check_bst(prev_sequence, post_sequence, mid, right, is_mirror);
    if(left_valid && right_valid){
        post_sequence.pb(root);
        return true;
    }
    return false;
}

signed main(){
    int n;
    cin >> n;
    vector<int> prev_sequence(n);
    for(int i = 0; i < n; i++) cin >> prev_sequence[i];
    vector<int> post_sequence;
    bool is_mirror = false;
    if(check_bst(prev_sequence, post_sequence, 0, n - 1, is_mirror)){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            if(i != 0) cout << ' ';
            cout << post_sequence[i];
        }
    }else{
        is_mirror = true;
        post_sequence.clear();
        if(check_bst(prev_sequence, post_sequence, 0, n - 1, is_mirror)){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                if(i != 0) cout << ' ';
                cout << post_sequence[i];
            }
        }else{
            cout << "NO";
        }
    }
    return 0;
}