#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    string s;
    getline(cin, s);
    // 去除空格
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    vector<int> nums;
    int cnt = 0;
    // 提取字符串中的数字
    for(int i = 0; i < s.size(); i++){
        if(isdigit(s[i])){
            cnt = cnt * 10 + (s[i] - '0');
        } else {
            if(cnt != 0){
                nums.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt != 0) nums.push_back(cnt);
    int price_sum = 0;
    for(int i = 0; i < nums.size(); i++){
        price_sum += nums[i];
    }
    cout << price_sum << endl;
    return 0;
}