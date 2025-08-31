#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int findspace(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' '){
            return i;
        }
    }
    return -1; // 没有空格
}

signed main(){
    int n;
    cin >> n;
    getchar(); // 读取掉换行符
    string mem;
    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int pos = findspace(s);
        if(pos == -1){
            cout << s << endl;
        }else{
            if(mem != ""){
                cout << mem << " ";
            }
            cout << s << endl;
            string first = s.substr(0, pos);
            mem = first;
        }
    }
    return 0;
}