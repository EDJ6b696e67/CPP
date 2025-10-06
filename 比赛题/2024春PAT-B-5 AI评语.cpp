#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
    int N, M;
    cin >> N >> M;
    // 存储学生信息，准考证号到分数的映射
    map<string, vector<int>> students;
    // 存储每个维度的所有分数
    vector<vector<int>> dimensions(5);
    // 读取学生信息
    for (int i = 0; i < N; ++i) {
        string id;
        cin >> id;
        vector<int> scores(5);
        for (int j = 0; j < 5; ++j) {
            cin >> scores[j];
            dimensions[j].push_back(scores[j]);
        }
        students[id] = scores;
    }
    // 计算每个维度的中位线值
    vector<int> medians(5);
    for (int i = 0; i < 5; ++i) {
        // 从大到小排序
        sort(dimensions[i].begin(), dimensions[i].end(), greater<int>());
        if (N % 2 == 1) {  // 奇数
            medians[i] = dimensions[i][(N + 1) / 2 - 1];
        } else {  // 偶数
            medians[i] = dimensions[i][N / 2 - 1];
        }
    }
    // 处理查询
    for (int i = 0; i < M; ++i) {
        string query_id;
        cin >> query_id;
        // 检查准考证号是否存在
        if (students.find(query_id) == students.end()) {
            cout << "Not Found" << endl;
            continue;
        }
        vector<int> scores = students[query_id];
        vector<pair<int, int>> positive, negative;  // 维度编号和差值
        // 分类各维度
        for (int j = 0; j < 5; ++j) {
            int score = scores[j];
            int median = medians[j];
            if (score >= median) {
                positive.push_back({j + 1, score - median});  // 维度编号从1开始
            } else {
                negative.push_back({j + 1, median - score});
            }
        }
        // 正向反馈排序：按差值非递增，再按维度编号递增
        sort(positive.begin(), positive.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        // 负向反馈排序：按差值非递减，再按维度编号递增
        sort(negative.begin(), negative.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });
        // 输出结果
        bool first = true;
        for (const auto& p : positive) {
            if (!first) {
                cout << " ";
            }
            cout << p.first;
            first = false;
        }
        for (const auto& p : negative) {
            if (!first) {
                cout << " ";
            }
            cout << "-" << p.first;
            first = false;
        }
        cout << endl;
    }
    return 0;
}