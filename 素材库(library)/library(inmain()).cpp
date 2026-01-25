#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    double num; //浮点数
    string s; //字符串
    string str;
    char c; //字符
    int a,b; //整数
    a = floor(num); //向下取整
    b = ceil(num); //向上取整
    set<int> myset; //集合
    map<string, int> mymap; //映射
    unordered_map<string, int> mymap; //无序映射
    transform(s.begin(), s.end(), s.begin(), ::toupper); //字符串转大写
    transform(s.begin(), s.end(), s.begin(), ::tolower); //字符串转小写
    str = to_string(a); //整数转字符串
    a = stoi(str); //字符串转整数
    str = s.substr(0, 3); //字符串截取
    cout << fixed << setprecision(2) << num << endl; //设置浮点数输出精度
    cout << setw(5) << setfill('0') << a << endl; //设置整数输出宽度和填充字符
    return 0;
}