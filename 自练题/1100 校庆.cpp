#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct idandbirth{
    string id;
    string birth;
};

bool cmp(const idandbirth &a, const idandbirth &b){
    return a.birth < b.birth;
}

signed main(){
    int n, m;
    cin >> n;
    unordered_map<string, string> alumni; // id -> birth
    string id;
    for(int i = 0; i < n; i++){
        cin >> id;
        string birth = id.substr(6, 8); // 第7-14位，共8位
        alumni[id] = birth;
    }

    cin >> m;
    int cnt_guest_is_student = 0;
    string oldest_alumni_id = "";
    string oldest_alumni_birth = ""; // 越小越老，比较字符串 yyyyMMdd 可直接比较
    string oldest_guest_id = "";
    string oldest_guest_birth = "";

    for(int i = 0; i < m; i++){
        cin >> id;
        string birth = id.substr(6, 8);
        // 维护最年长的来宾（所有来宾）
        if(oldest_guest_id.empty() || birth < oldest_guest_birth){
            oldest_guest_id = id;
            oldest_guest_birth = birth;
        }
        // 若是校友，计数并维护最年长的校友（在场的校友）
        if(alumni.find(id) != alumni.end()){
            cnt_guest_is_student++;
            if(oldest_alumni_id.empty() || birth < oldest_alumni_birth){
                oldest_alumni_id = id;
                oldest_alumni_birth = birth;
            }
        }
    }

    cout << cnt_guest_is_student << endl;
    if(cnt_guest_is_student > 0){
        cout << oldest_alumni_id << endl;
    } else {
        cout << oldest_guest_id << endl;
    }
    return 0;
}