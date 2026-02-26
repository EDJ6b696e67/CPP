#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

struct Node{
    int data;
    int num;
    Node(int d, int n): data(d), num(n) {}
    bool operator < (const Node& other) const{
        if(data != other.data){
            return data > other.data;
        }else{
            return num < other.num;
        }
    }
};

signed main(){
    int n;
    cin >> n;
    priority_queue<Node> min_heap;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        string cmd;
        cin >> cmd;
        if(cmd == "Deq"){
            if(min_heap.empty()) cout << "ERROR" << endl;
            else{
                cout << min_heap.top().data << '(' << min_heap.top().num << ')' << endl;
                min_heap.pop();
            }
        }else{
            int x;
            cin >> x;
            min_heap.emplace(x, cnt);
            cnt++;
        }
    }
    return 0;
}