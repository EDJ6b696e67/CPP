#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        if(a == 0){
            cout << string(b, '1') << endl;
            continue;
        }
        if(b == 0){
            cout << string(a, '0') << endl;
            continue;
        }

        char major_c, minor_c;
        int cnt_ma, cnt_mi;
        if(b > a){
            major_c = '1';
            cnt_ma = b;
            minor_c = '0';
            cnt_mi = a;
        }else{
            major_c = '0';
            cnt_ma = a;
            minor_c = '1';
            cnt_mi = b;
        }

        int times = cnt_mi + 1;
        int manum_per_t = cnt_ma / times;
        int remain = cnt_ma % times;
        string ans;
        for(int i = 0; i < times; i++){
            int current;
            if(i < remain) current = manum_per_t + 1;
            else current = manum_per_t;
            ans.append(current, major_c);
            if(i != times - 1){
                ans.pb(minor_c);
            }
        }
        cout << ans << endl;
    }
    return 0;
}