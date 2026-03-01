#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

struct Node{
    int parent = 0;
    int level = 0;
    vector<int> kids;
};

signed main() {
    int n, m;
    cin >> n >> m;
    vector<Node> nodes(n + 1);
    for(int i = 0; i < m; i++){
        int id, num;
        cin >> id >> num;
        for(int j = 0; j < num; j++){
            int kid_id;
            cin >> kid_id;
            nodes[id].kids.pb(kid_id);
            nodes[kid_id].parent = id;
        }
    }
    vector<pair<bool, int>> leave_level(n, {false, 0});
    queue<int> bfs;
    bfs.push(1);
    leave_level[0] = {true, 1};
    while(!bfs.empty()){
        int curr = bfs.front();
        bfs.pop();
        if(!nodes[curr].kids.empty()){
            leave_level[nodes[curr].level].second--;
            for(auto it : nodes[curr].kids){
                nodes[it].level = nodes[curr].level + 1;
                leave_level[nodes[it].level].first = true;
                leave_level[nodes[it].level].second++;
                bfs.push(it);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(leave_level[i].first){
            if(i != 0) cout << ' ';
            cout << leave_level[i].second;
        }
    }
    return 0;
}