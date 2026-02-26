#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        // 定义vector容器存储数组元素（0-based索引）
        vector<int> arr(n);
        // 循环读取n个数组元素，存入arr中
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        // 哈希表：记录每个元素「上一次出现的位置」（存储为1-based，方便计算）
        // key：数组元素值；value：该元素上一次出现的1-based位置（初始无值）
        unordered_map<int, int> last_place;
        // S_prev：记录「以i-1位置结尾的所有子数组的不同元素个数之和」（即前一个位置的累计值）
        int S_prev = 0;
        // ans：最终答案，存储所有子数组的权值总和（必须用long long，防止数值溢出）
        int ans = 0;
        
        // 遍历数组每个位置i（0-based），计算当前位置的贡献
        for(int i = 0; i < n; i++){
            // 获取当前位置的元素值a
            int a = arr[i];
            // prev_place：初始化元素a上一次出现的位置为0（0表示从未出现过）
            int prev_place = 0;
            // 如果哈希表中存在元素a的记录，更新prev_place为其上次出现的1-based位置
            if(last_place.find(a) != last_place.end()){
                prev_place = last_place[a];
            }
            
            // 核心递推公式：计算「以i位置结尾的所有子数组的不同元素个数之和」
            // i - prev_place + 1：当前元素a对累计值的新增贡献（转换为0-based到1-based的差值）
            // 例如：i=2（0-based）对应3（1-based），prev_place=1 → 3-1=2 → 0-based下是2-1+1=2
            int S_curr = S_prev + (i - prev_place + 1);
            
            // 累加当前位置的总贡献到答案中：
            // S_curr：以i结尾的所有子数组的不同元素个数之和
            // (n - i)：以i结尾的子数组可扩展的右边界数量（即子数组的右端点可以是i, i+1, ..., n-1，共n-i个）
            ans += S_curr * (n - i);
            
            // 更新哈希表：记录当前元素a的位置为「1-based的i+1」（方便后续计算）
            last_place[a] = i + 1;
            // 更新S_prev为当前的S_curr，供下一个位置计算使用
            S_prev = S_curr;
        }
        
        // 输出当前测试用例的最终答案
        cout << ans << endl;
    }
    return 0;
}