#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// 学生信息结构体
struct StudentInfo{
    double score = 0.0;
    int cnt = 0;
};

// 自定义排序规则
bool cmp(const tuple<string, int, int> &a, const tuple<string, int, int> &b){
    if(get<1>(a) != get<1>(b)){
        return get<1>(a) > get<1>(b);
    } else if(get<2>(a) != get<2>(b)){
        return get<2>(a) < get<2>(b);
    } else {
        return get<0>(a) < get<0>(b);
    }
}

signed main(){
    int n;
    cin >> n;

    // 使用unordered_map存储学校信息
    unordered_map<string, StudentInfo> StudentMap;
    for(int i = 0; i < n; i++){
        string id;
        int per_score;
        string school;
        cin >> id >> per_score >> school;
        // 将学校名称转换为小写
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if(StudentMap.find(school) == StudentMap.end()){
            StudentMap[school] = StudentInfo();
        }
        StudentMap[school].cnt++;
        // 根据考试类型调整分数
        if(id[0] == 'B'){
            StudentMap[school].score += per_score / 1.5;
        } else if(id[0] == 'A'){
            StudentMap[school].score += per_score;
        } else if(id[0] == 'T'){
            StudentMap[school].score += per_score * 1.5;
        }
    }

    // 将结果存入vector
    vector<tuple<string, int, int>> res;
    for(auto &p : StudentMap){
        res.push_back(make_tuple(p.first, (int)p.second.score, p.second.cnt));
    }
    // 自定义排序
    sort(res.begin(), res.end(), cmp);
    // 输出排名结果
    cout << res.size() << endl;

    // 记录当前排名和前一个分数
    int rank = 0, pre_score = -1;
    // 处理排名相同的情况
    for(int i = 0; i < res.size(); i++){
        if(get<1>(res[i]) != pre_score){
            rank = i + 1;
            pre_score = get<1>(res[i]);
        }
        cout << rank << " " << get<0>(res[i]) << " " << get<1>(res[i]) << " " << get<2>(res[i]) << endl;
    }

    return 0;
}