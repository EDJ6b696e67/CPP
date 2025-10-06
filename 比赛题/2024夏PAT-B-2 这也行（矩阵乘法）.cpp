#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 矩阵乘法
vector<vector<int>> operator*(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int n = a.size(), m = a[0].size(), p = b[0].size();
    vector<vector<int>> c(n, vector<int>(p, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            for(int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

// 检查矩阵格式
bool checkMatrixFormat(const vector<vector<int>>& result, const vector<vector<int>>& a) {
    if(result[0][0] == a[0][0]*11 && result[0][1] == a[0][1]*11 &&
       result[1][0] == a[1][0]*11 && result[1][1] == a[1][1]*11) {
        cout << "1" << endl;
        return true;
    } else {
        cout << "0" << endl;
        return false;
    }
}

signed main(){           
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        // 2 * 2 矩阵输入
        vector<vector<int>> a(2, vector<int>(2));
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                cin >> a[j][k];
            }
        }
        // 矩阵自乘
        vector<vector<int>> result = a * a;
        // 检查矩阵格式
        checkMatrixFormat(result, a);
    }
}