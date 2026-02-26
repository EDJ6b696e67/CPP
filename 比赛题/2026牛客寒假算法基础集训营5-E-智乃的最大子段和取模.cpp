#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int n, p;
    cin >> n >> p;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int pre_x = 0; // 当前前缀和 mod p
    int max_mod = -1; // 当前找到的最大取模子段和
    int ans_l = 0, ans_r = 0; // 答案区间 [ans_l, ans_r]
    set<pair<int, int>> myset; // 存储已出现的前缀和及对应位置（前缀和, index）
    myset.insert({0, 0}); // 初始前缀和为0，对应位置0（表示从0开始）

    for(int i = 0; i < n; i++){
        pre_x = (pre_x + arr[i]) % p;
        int x = pre_x; // 当前前缀和 mod p

        // 查找第一个前缀和 > x 的元素（用于计算通过减法得到接近 p 的值）
        auto curr = myset.upper_bound({x, INT_MAX});
        int val_1 = -1; // 通过找到大于 x 的前缀得到的候选值
        int val_2 = x;  // 从0到i的子段和（即直接前缀和）作为另一个候选值
        if(curr != myset.end()){
            // (x - prev + p) % p 表示以 curr->first 为左前缀时的子段和 mod p
            val_1 = (x - curr -> first + p) % p;
        }
        int curr_val;
        if(val_1 == -1){
            curr_val = val_2;
        }else{
            curr_val = max(val_1, val_2);
        }

        if (curr_val > max_mod) {
            max_mod = curr_val;
            if (val_1 != -1 && val_1 >= val_2) {
                // 使用 curr->first 对应的前缀作为左边界（curr->second）
                ans_l = curr -> second;
            } else {
                // 使用最小前缀（myset.begin()）对应的位置作为左边界，通常为0
                ans_l = myset.begin() -> second;
            }
            ans_r = i; // 右边界为当前索引 i
        }

        if (max_mod == p - 1) {
            // 达到可能的最大值，提前结束
            break;
        }

        // 将当前前缀和与位置（i+1）插入集合，位置用 i+1 表示前缀长度
        myset.insert({x, i + 1});
    }
    cout << ans_l << ' ' << ans_r << ' ' << max_mod << endl;
    return 0;
}