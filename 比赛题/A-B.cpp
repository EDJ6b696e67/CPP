#include <bits/stdc++.h>
using namespace std;
#define int long long

// 预处理：去掉 "0." 并补齐位数
string getDecimalPart(const string &s) {
    // 假设 s 格式始终为 "0.xxx"
    return s.substr(2);
}

int checkbigger(string a, string b){
    for(int i = 0; i < min(a.size(),b.size()); i++){
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return 0;
    }
    return 2; // equal
}

string subtraction(string a, string b){
    string ans = "";
    int carry = 0;
    for(int i = 0; i < a.size(); i++){
        int x = a[a.size() - 1 - i] - '0';
        int y = (i < b.size()) ? b[b.size() - 1 - i] - '0' : 0;
        x -= carry;  // 先扣除上一次借位
        if(x < y){
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        ans.push_back((char)(x - y + '0'));
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

void swap(string &a, string &b){
    string temp = a;
    a = b;
    b = temp;
}

signed main(){
    string a,b;
    cin >> a >> b;
    a = getDecimalPart(a);
    b = getDecimalPart(b);
    //在后面补0
    if(a.size() < b.size()) a += string(b.size() - a.size(), '0');
    else if(b.size() < a.size()) b += string(a.size() - b.size(), '0');
    int small=0;
    if(checkbigger(a,b) == 0){
        swap(a,b);
        small = 1;
    }else if(checkbigger(a,b) == 2){
        cout << "0\n";
        return 0;
    }
    string ans = subtraction(a,b);
    if(small) cout << "-";
    //去除末尾的多余0
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    cout << "0." << ans << endl;
}