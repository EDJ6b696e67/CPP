#include <bits/stdc++.h>
using namespace std;

// 对齐程序1：统一身份证校验函数（18位纯数字）
bool isIllegal(const string &ss) {
    if (ss.size() != 18) return true;
    for (char i : ss) 
        if (i < '0' || i > '9') return true;
    return false;
}

// 对齐程序1：结构体命名/字段完全统一
struct node {
    string name, id, Time;
    int illness, order;
};

// 对齐程序1：排序规则（时间升序 → 提交顺序升序）
bool cmp (const node &a, const node &b) {
    if (a.Time != b.Time) return a.Time < b.Time;
    return a.order < b.order;
}

signed main() {
    // 全局部变量（保留程序2优点）
    int D, P;
    cin >> D >> P;
    
    // 对齐程序1：核心数据结构
    map<string, int> lastGet;    // 记录每个人上次领取的天数
    set<string> gotten;          // 重病人员去重（身份证唯一）
    vector<node> ill;            // 存储重病人员信息

    // 对齐程序1：天数从 1 开始计数（核心逻辑正确）
    for (int day = 1; day <= D; day++) {
        int t, s;
        cin >> t >> s;
        vector<node> Record;     // 每日申请列表（局部变量，程序2优点）
        Record.resize(t);
        int providedNum = 0;     // 当日已发放数量

        // 读取当日所有申请
        for (int j = 0; j < t; j++) {
            cin >> Record[j].name >> Record[j].id >> Record[j].illness >> Record[j].Time;
            Record[j].order = j; // 记录提交顺序

            // 对齐程序1：身份证非法 → 直接标记无效（过滤）
            if (isIllegal(Record[j].id)) {
                Record[j].name = "";
            } else {
                // 初始化领取记录：从未领取 → 上次领取天数为-30（满足间隔）
                if (!lastGet.count(Record[j].id)) 
                    lastGet[Record[j].id] = -30;
                
                // 对齐程序1：重病人员去重（仅用身份证，唯一标识）
                if (Record[j].illness == 1 && !gotten.count(Record[j].id)) {
                    ill.push_back(Record[j]);
                    gotten.insert(Record[j].id);
                }
            }
        }

        // 排序 + 发放物资（完全对齐程序1正确逻辑）
        sort(Record.begin(), Record.end(), cmp);
        for (int j = 0; j < t && providedNum < s; j++) {
            // 有效身份证 + 间隔超过P天 → 发放
            if (Record[j].name != "" && day - lastGet[Record[j].id] > P) {
                lastGet[Record[j].id] = day;
                providedNum++;
                cout << Record[j].name << ' ' << Record[j].id << endl;
            }
        }
    }

    // 输出所有重病人员
    for (auto &i : ill) 
        cout << i.name << ' ' << i.id << '\n';
    
    return 0;
}