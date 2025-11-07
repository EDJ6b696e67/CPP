#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        int n;
        cin >> n;
        bool flag = false;
        vector<int> a;
        for(int j = 1; j <= n; j++){
            if(n % j == 0){
                a.push_back(j);
            }
        }
        if(a.size() < 4){
            cout << "No" << endl;
            continue;
        }
        for(int x = 0; x < a.size(); x++){
            for(int y = x + 1; y < a.size(); y++){
                for(int z = y + 1; z < a.size(); z++){
                    for(int w = z + 1; w < a.size(); w++){
                        if((a[x] + a[y] + a[z] + a[w]) % n == 0){
                            flag = true;
                            goto A;
                        }
                    }
                }
            }
        }
        A:
            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
    }
    return 0;
}