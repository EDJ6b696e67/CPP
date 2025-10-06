#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

//定义两个栈
stack<int> s1;
stack<char> s2;

signed main(){
    int n;
    cin >> n;
    //输入数字和符号
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        s1.push(num);
    }
    for(int i = 0; i < n - 1; i++){
        char c;
        cin >> c;
        s2.push(c);
    }
    //从后往前计算
    while(!s2.empty()){
        int a = s1.top();
        s1.pop();
        int b = s1.top();
        s1.pop();
        char c = s2.top();
        s2.pop();
        if(c == '+'){
            s1.push(a + b);
        }else if(c == '-'){
            s1.push(b - a);
        }else if(c == '*'){
            s1.push(a * b);
        }else if(c == '/'){
            //注意除0错误
            if(a == 0){
                cout << "ERROR: " << b << "/0" << endl;
                return 0;
            }
            s1.push(b / a);
        }
    }
    cout << s1.top() << endl;
    return 0;
}