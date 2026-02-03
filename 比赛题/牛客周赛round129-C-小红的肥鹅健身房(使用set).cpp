#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

set<int> myset; //集合

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    int cnt_of_craft = 0;
    int cnt_of_coins = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x;
            cin >> x;
            if(x == 0) continue;
            if(myset.find(x) == myset.end()){
                myset.insert(x);
            }else{
                loop:
                cnt_of_craft++;
                if(x + 1 >= k) cnt_of_coins++;
                myset.erase(x);
                if(myset.find(x + 1) == myset.end()){
                    myset.insert(x + 1);
                }else {
                    x = x + 1;
                    goto loop;
                }
            }
        }
    }
    cout << cnt_of_craft << " " << cnt_of_coins << endl;
    return 0;
}