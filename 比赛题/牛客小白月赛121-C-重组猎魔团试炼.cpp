#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    // 提高输入输出效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, D;
    cin >> n >> D;
    string s;
    cin >> s;

    int ans = -1;
    // 枚举所有非空子集（共 2^n - 1 种）
    for(int mask = 1; mask < (1 << n); mask++){
        vector<char> digits;
        // 提取子集对应的数字字符
        for(int i = 0; i < n; i++){
            // 判断第 i 位是否在子集中
            if(mask & (1 << i))
                digits.push_back(s[i]);
        }
        // 对子集中的数字字符进行全排列
        sort(digits.begin(), digits.end());
        do{
            // 将排列的数字字符转为整数，允许前导零
            int num = 0;
            // 计算数字值
            for (char c : digits){
                num = num * 10 + (c - '0');
            }
            // 检查是否能被 D 整除
            if(num % D == 0){
                if(ans == -1 || num < ans){
                    ans = num;
                }
            }
        } while(next_permutation(digits.begin(), digits.end()));
    }
    
    cout << ans << endl;
    return 0;
}