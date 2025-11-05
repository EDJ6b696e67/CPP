#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// 定义结构体存储格式化信息
struct format{
    string originalId;
    char level;
    string roomId;
    string date;
    string studentId;
    int score;
};

signed main(){
    int n, m;
    cin >> n >> m;
    vector<format> formats(n);

    // 读取并格式化输入数据
    for(int i = 0; i < n; i++){
        cin >> formats[i].originalId;
        cin >> formats[i].score;
        formats[i].level = formats[i].originalId[0];
        formats[i].roomId = formats[i].originalId.substr(1, 3);
        formats[i].date = formats[i].originalId.substr(4, 6);
        formats[i].studentId = formats[i].originalId.substr(10, 3);
    }

    // 按照原始ID排序
    sort(formats.begin(), formats.end(), [](const format &a, const format &b){
        if(a.score != b.score) return a.score > b.score;
        return a.originalId < b.originalId;
    });

    // 处理查询
    for(int i = 0; i < m; i++){
        int queryType;
        cin >> queryType;
        if(queryType == 1){
            char level;
            cin >> level;
            cout << "Case " << i + 1 << ": " << queryType << " " << level << endl;
            bool found = false;
            for(const auto &f : formats){
                if(f.level == level){
                    cout << f.originalId << " " << f.score << endl;
                    found = true;
                }
            }
            if(!found){
                cout << "NA" << endl;
            }
        } else if(queryType == 2){
            string roomId;
            cin >> roomId;
            cout << "Case " << i + 1 << ": " << queryType << " " << roomId << endl;
            int count = 0;
            int totalScore = 0;
            for(const auto &f : formats){
                if(f.roomId == roomId){
                    count++;
                    totalScore += f.score;
                }
            }
            if(count == 0){
                cout << "NA" << endl;
            } else {
                cout << count << " " << totalScore << endl;
            }
        } else if(queryType == 3){
            string date;
            cin >> date;
            cout << "Case " << i + 1 << ": " << queryType << " " << date << endl;
            // 统计每个考场的学生数量
            map<string, int> studentCount;
            for(const auto &f : formats){
                if(f.date == date){
                    studentCount[f.roomId]++;
                }
            }
            // 输出结果
            if(studentCount.empty()){
                cout << "NA" << endl;
            } else {
                vector<pair<string, int>> results(studentCount.begin(), studentCount.end());
                // 按照数量降序，考场ID升序排序
                sort(results.begin(), results.end(), [](const pair<string, int> &a, const pair<string, int> &b){
                    if(a.second != b.second) return a.second > b.second;
                    return a.first < b.first;
                });
                for(const auto &res : results){
                    cout << res.first << " " << res.second << endl;
                }
            }
        }
    }
    return 0;
}