#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
char num[10][4] = {
    {'*','.','.','.'},
    {'*','.','*','.'},
    {'*','*','.','.'},
    {'*','*','.','*'},
    {'*','.','.','*'},
    {'*','*','*','.'},
    {'*','*','*','*'},
    {'*','.','*','*'},
    {'.','*','*','.'},
    {'.','*','*','*'}
};

int checkcharactor(vector<vector<char>> c, int i, int j){
    if(c[i+2][j] != '.' || c[i+2][j+1] != '.'){
        return -1;
    }
    for(int k = 0; k < 10; k++){
        if(c[i][j] == num[k][0] && c[i][j+1] == num[k][1] && c[i+1][j] == num[k][2] && c[i+1][j+1] == num[k][3]){
            return (k+1) % 10;
        }
    }
    return -1; // 没有匹配到任何字符
}

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> s(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
        }
    }
    vector<int> a(10, 0);
    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m-1; j++){
            int k = checkcharactor(s, i, j);
            if(k != -1){
                a[k]++;
            }
        }
    }
    for(int i = 1; i < 10; i++){
        if(i != 1){
            cout << " ";
        }
        cout << a[i];
    }
    cout << " " << a[0];
}