#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

bool cmp(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b){
    if(a.second.first != b.second.first) return a.second.first > b.second.first;
    if(a.second.second != b.second.second) return a.second.second > b.second.second;
    return a.first < b.first;
}

signed main() {
    static unordered_map<string, pair<int, int>> map;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, m;
        cin >> x >> m;
        for(int j = 0; j < m; j++){
            string id;
            cin >> id;
            map[id].first += x;
            map[id].second++;
        }
    }
    vector<pair<string, pair<int, int>>> data(map.begin(), map.end());
    sort(data.begin(), data.end(), cmp);
    cout << data[0].second.first << ' ' << data[0].second.second << endl;
    pair<int, int> max;
    max = data[0].second;
    for(int i = 0; i < data.size(); i++){
        if(data[i].second == max){
            if(i != 0) cout << ' ';
            cout << data[i].first;
        }else break;
    }
    return 0;
}