#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    double num;
    string s;
    string str;
    char c;
    int a,b;
    set<int> myset;
    unordered_map<string, int> mymap;
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    str = to_string(a);
    a = stoi(str);
    str = s.substr(0, 3);
    cout << fixed << setprecision(2) << num << endl;
    cout << setw(5) << setfill('0') << a << endl;
    return 0;
}