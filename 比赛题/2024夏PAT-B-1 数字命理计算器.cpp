#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int minglishu(char c){
    int a = c - 'a';
    return a%9 + 1;
}

bool check(int mls){
    if((0 < mls && mls < 10) || mls == 11 || mls == 22) return true;
    return false;
}

signed main(){
    int n;
    cin >> n;
    cin.ignore(); // 忽略换行符
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        getline(cin, s[i]);
        //去除空格并将大写字符转为小写
        s[i].erase(remove(s[i].begin(), s[i].end(), ' '), s[i].end());
        transform(s[i].begin(), s[i].end(), s[i].begin(), ::tolower);
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i].size(); j++) {
            sum += minglishu(s[i][j]);
        }
        do{
            if(check(sum)){
                break; // 找到符合条件的数字，跳出循环
            }else{
                //将sum的各个位数相加
                int new_sum = 0;
                while(sum > 0) {
                    new_sum += sum % 10;
                    sum /= 10;
                }
                sum = new_sum;
            }
        }while(!check(sum));
        cout << sum << endl; // 输出最终的数字
        sum = 0; // 重置sum为0以处理下一行
    }
}