#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int N, M;
    cin >> N >> M;

    vector<int> h(1);
    unordered_map<int, int> pos;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        h.pb(x);
        int j = h.size() - 1;
        while (j > 1 && h[j] > h[j / 2]) {
            swap(h[j], h[j / 2]);
            j /= 2;
        }
    }

    for (int i = 1; i < h.size(); i++) pos[h[i]] = i;

    cin.ignore();

    string s;
    for (int i = 0; i < M; i++) {
        getline(cin, s);
        stringstream ss(s);
        vector<string> v;
        string t;
        while (ss >> t) v.pb(t);

        bool ok = false;

        if (v.size() == 4) {
            int x = stoi(v[0]);
            if (pos.count(x) && pos[x] == 1) ok = true;
        }
        else if (v.size() == 5) {
            int x = stoi(v[0]), y = stoi(v[2]);
            if (pos.count(x) && pos.count(y) && pos[x] != pos[y] && pos[x] / 2 == pos[y] / 2)
                ok = true;
        }
        else if (v.size() == 6) {
            int x = stoi(v[0]), y = stoi(v[5]);
            if (pos.count(x) && pos.count(y) && pos[y] / 2 == pos[x])
                ok = true;
        }
        else if (v.size() == 7) {
            int x = stoi(v[0]), y = stoi(v[6]);
            if (pos.count(x) && pos.count(y)) {
                if (v[3] == "left" && pos[x] == pos[y] * 2) ok = true;
                if (v[3] == "right" && pos[x] == pos[y] * 2 + 1) ok = true;
            }
        }

        cout << (ok ? 1 : 0);
    }

    return 0;
}