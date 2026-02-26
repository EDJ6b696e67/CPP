#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

signed main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, k;
        cin >> a >> b >> k;
        queue<pair<int, int>> q;
        vector<bool> visited(1e7 + 2, false);
        visited[a] = true;
        q.push(make_pair(a, 0));
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            if(curr.first == b){
                cout << curr.second << endl;
                goto NEXT;
            }else{
                pair<int, int> next;
                next.second = curr.second + 1;
                if(curr.first % 10 != 0){
                    string s;
                    s = to_string(curr.first);
                    reverse(s.begin(), s.end());
                    next.first = stoll(s);
                    if(!visited[next.first] && next.first <= b * 10){
                        visited[next.first] = true;
                        q.push(next);
                    }
                }
                next.first = curr.first + k;
                if(!visited[next.first] && next.first <= b * 10){
                    visited[next.first] = true;
                    q.push(next);
                }
            }
        }
        cout << -1 << endl;
        NEXT:
    }
    return 0;
}