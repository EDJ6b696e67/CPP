#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

unordered_map<string, pair<int, string>> mymap;

string check(const string& name1, const string& name2){
    int cnt1 = 0, cnt2 = 0;
    string a = name1, b = name2;
    while(a != ""){
        cnt2 = 0;
        b = name2;
        while(b != ""){
            if(cnt1 >= 4 && cnt2 >= 4) return "Yes";
            if(a == b) return "No";
            b = mymap[b].second;
            cnt2++;
        }
        a = mymap[a].second;
        cnt1++;
    }
    return "Yes";
}

signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string name, firstname;
        cin >> name >> firstname;
        if(firstname.back() == 'n') mymap[name] = {1, firstname.substr(0, firstname.size() - 4)};
        else if(firstname.back() == 'r') mymap[name] = {0, firstname.substr(0, firstname.size() - 7)};
        else if(firstname.back() == 'm') mymap[name] = {1, ""};
        else mymap[name] = {0, ""};
    }
    int m;
    cin >> m;
    while(m--){
        string name1, firstname1, name2, firstname2;
        cin >> name1 >> firstname1 >> name2 >> firstname2;
        if(!mymap.count(name1) || !mymap.count(name2)) cout << "NA" << endl;
        else if(mymap[name1].first == mymap[name2].first) cout << "Whatever" << endl;
        else cout << check(name1, name2) << endl;
    }
    return 0;
}