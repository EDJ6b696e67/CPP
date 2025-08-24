#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
// 主栈存储元素
stack<int> s;
// 辅助栈存储当前的最大值（与主栈元素一一对应）
stack<int> max_stack;
signed main(){
    int n;
    cin >> n;
    string command;
    while(n--){
        cin >> command;
        //将值为 X 的元素入栈
        if(command == "Push"){
            int x;
            cin >> x;
            s.push(x);
            // 辅助栈顶始终是当前最大值
            if(max_stack.empty() || x > max_stack.top()){
                max_stack.push(x);
            } else {
                max_stack.push(max_stack.top());
            }
        }
        //将栈顶元素出栈
        if(command == "Pop"){
            if(s.empty()){
                cout << "ERROR" << endl;
            } else {
                cout << s.top() << endl;
                s.pop();
                max_stack.pop();  // 同步弹出辅助栈元素
            }
        }
        //返回此刻堆栈中最大元素的值
        if(command == "PeekMax"){
            if(s.empty()){
                cout << "ERROR" << endl;
            } else {
                // 直接从辅助栈顶获取最大值
                cout << max_stack.top() << endl;
            }
        }
    }
    return 0;
}