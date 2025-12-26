#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

int translate_month(const string& month_str) {
    static const unordered_map<string, int> month_map = {
        {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4},
        {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8},
        {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
    };
    auto it = month_map.find(month_str);
    if (it != month_map.end()) {
        return it->second;
    }
    return -1;
}

bool check_symmetry_date(string date) {
    int len = date.length();
    for(int i = 0; i < len / 2; i++) {
        if(date[i] != date[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

signed main(){
    int n;
    cin >> n;
    vector<string> date(n);
    for(int i = 0; i < n; i++){
        string month_str;
        string day;
        string year;
        cin >> month_str >> day >> year;
        int month = translate_month(month_str);
        day = day.substr(0, day.size() - 1); // Remove the comma
        date[i] = year;
        if(month < 10){
            date[i] += "0";
        }
        date[i] += to_string(month);
        if(stoi(day) < 10){
            date[i] += "0";
        }
        date[i] += day;
    }

    for(int i = 0; i < n; i++){
        while(date[i].length() < 8){
            date[i] = "0" + date[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(check_symmetry_date(date[i])){
            cout << "Y";
        } else {
            cout << "N";
        }
        cout << ' ' << date[i] << endl;
    }

    return 0;
}