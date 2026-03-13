#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

struct Team{
    string name;  // 队伍名称
    int ac;        // 解题数
    int time;        // 罚时
};

bool cmp(const Team &a, const Team &b){
    if (a.ac != b.ac){
        return a.ac > b.ac;
    }else{
        return a.time < b.time;
    }
}

// 计算选择某一届时的最优排名
// origin_list 目标届的原始队伍列表
// other_map 另一届的队伍哈希表（用于判断双资格队伍）
// lzr_team lzr在目标届的参赛信息
int get_best_rank(const vector<Team>& origin_list, const unordered_map<string, Team>& other_map, const Team& lzr_team){
    // 构造最优参赛列表：仅保留非双资格队伍 + lzr自身
    vector<Team> best_list;
    for(const auto& team : origin_list){
        if (other_map.find(team.name) == other_map.end()) best_list.push_back(team);
    }
    best_list.push_back(lzr_team);

    sort(best_list.begin(), best_list.end(), cmp);

    for(int i = 0; i < best_list.size(); i++){
        if(best_list[i].name == "lzr010506") return i + 1;
    }
}

signed main(){
    int n;
    cin >> n;
    unordered_map<string, Team> map46;
    vector<Team> list46;
    for(int i = 0; i < n; i++){
        Team team;
        cin >> team.name >> team.ac >> team.time;
        map46[team.name] = team;
        list46.push_back(team);
    }

    int m;
    cin >> m;
    unordered_map<string, Team> map47;
    vector<Team> list47;
    for(int i = 0; i < m; i++){
        Team team;
        cin >> team.name >> team.ac >> team.time;
        map47[team.name] = team;
        list47.push_back(team);
    }

    Team lzr46 = map46["lzr010506"];
    Team lzr47 = map47["lzr010506"];

    int rank46 = get_best_rank(list46, map47, lzr46);
    int rank47 = get_best_rank(list47, map46, lzr47);

    cout << min(rank46, rank47) << endl;

    return 0;
}