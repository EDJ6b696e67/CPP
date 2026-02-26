#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back 
#define endl "\n"

struct PairHash{
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};

signed main(){
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<pair<int, int>, string, PairHash> hush_map;
    for(int i = 0; i < n; i++){
        int title, data;
        cin >> title;
        cin.ignore();
        cin >> data;
        cin.ignore();
        string ans;
        getline(cin, ans);
        hush_map[{title, data}] = ans;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int cur_title, cur_data;
        cin >> cur_title >> cur_data;
        if(hush_map.find({cur_title, cur_data}) != hush_map.end()){
            string s = hush_map[{cur_title, cur_data}];
            for(auto c : s){
                if(c == '#'){
                    cout << endl;
                }else{
                    cout << c;
                }
            }
        }else{
            cout << 0;
        }
        cout << endl;
    }
    return 0;
}