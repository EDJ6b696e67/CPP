#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
// 定义一个结构体来存储方案信息
struct SchemeInfo {
    bool valid;
    int diag_sum;
    int id;
};
signed main(){
    int n, m;
    cin >> n >> m;
    const int size = n * n;
    vector<SchemeInfo> valid_schemes;
    // 处理每个方案
    for (int id = 1; id <= m; ++id) {
        vector<vector<int>> board(n, vector<int>(n));
        vector<pair<int, int>> pos(size + 1);
        vector<bool> used(size + 1, false);  // 用于检查数字唯一性
        bool input_valid = true;
        // 读取棋盘并记录位置
        for (int i = 0; i < n && input_valid; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
                int num = board[i][j];
                // 检查数字是否在有效范围内且未被使用过
                if (num < 1 || num > size || used[num]) {
                    input_valid = false;
                } else {
                    used[num] = true;
                    pos[num] = {i, j};
                }
            }
        }
        // 如果输入无效，直接标记为无效方案
        if (!input_valid) {
            continue;
        }
        // 验证相邻性
        bool valid = true;
        auto [x_prev, y_prev] = pos[1];
        // 检查1到size的连续性
        for (int i = 2; i <= size && valid; ++i) {
            auto [x_curr, y_curr] = pos[i];
            if (abs(x_prev - x_curr) + abs(y_prev - y_curr) != 1) {
                valid = false;
            }
            x_prev = x_curr;
            y_prev = y_curr;
        }
        // 检查最后一个数字与1是否相邻
        if (valid) {
            auto [x1, y1] = pos[1];
            if (abs(x_prev - x1) + abs(y_prev - y1) != 1) {
                valid = false;
            }
        }
        // 计算对角线和（仅对有效方案）
        if (valid) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += board[i][i];           // 主对角线
                sum += board[i][n - 1 - i];   // 副对角线
            }
            valid_schemes.push_back({true, sum, id});
        }
    }
    // 处理结果
    if (valid_schemes.empty()) {
        cout << "0" << endl;
        return 0;
    }
    // 找到最大对角线和
    int max_sum = 0;
    for (const auto& s : valid_schemes) {
        if (s.diag_sum > max_sum) {
            max_sum = s.diag_sum;
        }
    }
    // 收集所有具有最大和的方案ID
    vector<int> result;
    for (const auto& s : valid_schemes) {
        if (s.diag_sum == max_sum) {
            result.push_back(s.id);
        }
    }
    // 排序并输出
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << result[i];
    }
    cout << endl;
    return 0;
}