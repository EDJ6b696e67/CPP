#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int N, K;
vector<int> inputSeq;  // 入队序列

/*
我们规定：操作允许两端入队，出队只能从左端（front）进行
模拟过程：已有指针 i 表示下一个待入队元素（按 inputSeq 顺序），
j 表示已经出队的元素数目（目标出队序列 nextOutput）。
deque<int> dq 为当前双端队列（队首为 front）。
*/
// 为了避免重复搜索，用 memo 保存状态
// 状态由 i, j 以及当前 deque 中元素构成（序列比较短）
 
unordered_set<string> memo;
 
string encodeState(int i, int j, const deque<int>& dq){
    string key = to_string(i) + "#" + to_string(j) + "#";
    for(auto &x : dq)
        key += to_string(x) + ",";
    return key;
}
 
bool dfs(int i, int j, deque<int>& dq, const vector<int>& target){
    if(j == target.size()){
        // 出队顺序匹配完成，要求最后队列为空且所有出队操作都合法
        return true;
    }
    string state = encodeState(i, j, dq);
    if(memo.count(state)) return false;
    memo.insert(state);
    bool possible = false;
    // 如果队列非空且队首与目标当前相同，则可以出队
    if(!dq.empty() && dq.front() == target[j]){
        int frontVal = dq.front();
        dq.pop_front();
        possible = dfs(i, j+1, dq, target);
        dq.push_front(frontVal);
        if(possible) return true;
    }
    // 如果还有入队操作，则试着入队（可选左端或右端）
    if(i < inputSeq.size()){
        // 入队至左侧
        dq.push_front(inputSeq[i]);
        if(dfs(i+1, j, dq, target)) return true;
        dq.pop_front();
 
        // 入队至右侧
        dq.push_back(inputSeq[i]);
        if(dfs(i+1, j, dq, target)) return true;
        dq.pop_back();
    }
    return false;
}

signed main(){
    cin >> N >> K;
    inputSeq.resize(N);
    for (int i = 0; i < N; i++){
        cin >> inputSeq[i];
    }
    for (int k = 0; k < K; k++){
        vector<int> candidate(N);
        for (int i = 0; i < N; i++){
            cin >> candidate[i];
        }
        memo.clear();
        deque<int> dq;
        bool ok = dfs(0, 0, dq, candidate);
        if(ok){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}