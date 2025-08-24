#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M = 99;
int mod(int a){
    return a % M;
}
// 从右边开始切分：将数字从右向左每两位一组（剩余最后一组可能只有1位），求各组数字之和
int cut_from_right(string s){
    int sum = 0;
    int i = s.size()-1;
    while(i >= 1){
        sum += (s[i-1]-'0') * 10 + (s[i]-'0');
        i -= 2;
    }
    if(i == 0){
        sum += s[0]-'0'; // 补上剩余的1位
    }
    return sum;
}
// 从左边开始切分：将数字从左向右每两位一组（最后一组可能只有1位），求和
int cut_from_left(string s){
    int sum = 0;
    int i = 0;
    int n = s.size();
    while(i <= n-2){
        sum += (s[i]-'0') * 10 + (s[i+1]-'0');
        i += 2;
    }
    if(i < n){
        sum += s[i]-'0';
    }
    return sum;
}
signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int a = cut_from_right(s);
        int b = cut_from_left(s);
        if(mod(a) == mod(b)){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
}