#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

const int MAX = 31;
const int INF = 1e10;

signed main() {
    int m, c, q;
    cin >> m >> c >> q;

    vector<int> a(m);

    vector<vector<int>> next(m, vector<int>(MAX)); // next[i][j]：从i走2^j步到的位置
    vector<vector<int>> sum_of_steps(m, vector<int>(MAX)); // sum_of_steps[i][j]：从i走2^j步的累计和

    for(int i = 0; i < m; i++){
        cin >> a[i];
        next[i][0] = (i + a[i]) % m;
        sum_of_steps[i][0] = a[i];
    }

    for(int j = 1; j < MAX; j++){
        for(int i = 0; i < m; i++){
            int another = next[i][j - 1]; // 先走到 2^(j-1) 步的位置
            next[i][j] = next[another][j - 1]; // 再走 2^(j-1) 步，总共 2^j 步
            if(sum_of_steps[i][j - 1] + sum_of_steps[i][j - 1] >= INF){
                sum_of_steps[i][j] = INF;
            }else{
                sum_of_steps[i][j] = sum_of_steps[i][j - 1] + sum_of_steps[another][j - 1];
            }
        }
    }

    while(q--){
        int x;
        cin >> x;
        if(x > c){
            cout << "No" << endl;
            continue;
        }else if(x == c){
            cout << "Yes" << endl;
            continue;
        }
        
        int diff = c - x;
        int i = x % m;
        int sum = 0;

        // 从最大的2^30步开始枚举，贪心累加
        for(int j = MAX - 1; j >= 0; j--){
            // 若加上当前2^j步的和不超过diff，就走这一步
            if(sum + sum_of_steps[i][j] <= diff){
                sum += sum_of_steps[i][j];
                i = next[i][j];
            }
        }

        if(sum == diff) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}