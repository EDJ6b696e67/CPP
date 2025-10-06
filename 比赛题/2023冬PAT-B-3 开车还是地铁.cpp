#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

// 2023年每个月的天数（预计算，避免重复计算）
const int DAYS_IN_MONTH[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 预计算每月1日的星期几（从1月开始），0表示周日
const int FIRST_DAY_OF_MONTH[] = {-1, 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
// 计算2023年M月D日是星期几（优化版本）
// 0表示周日，1表示周一，...，6表示周六

inline int getWeekday(int M, int D) {
    // 使用预计算的每月第一天星期几，避免累加计算
    return (FIRST_DAY_OF_MONTH[M] + D - 1) % 7;
}

// 从车牌中提取最后一位数字（优化版本）
inline int getLastDigit(const string& plate) {
    // 直接从后往前遍历，找到第一个数字就返回
    for (auto it = plate.rbegin(); it != plate.rend(); ++it) {
        if (isdigit(*it)) {
            return *it - '0';
        }
    }
    return -1;  // 题目保证至少有一个数字，不会执行到这里
}

// 判断是否禁行（优化版本）
bool isBanned(int M, int D, const string& plate) {
    const int lastDigit = getLastDigit(plate);
    // 先判断是否在亚运限行期间（9月18日至10月9日）
    if ((M == 9 && D >= 18) || (M == 10 && D <= 9)) {
        // 单日单号通行（双号禁行），双日双号通行（单号禁行）
        return (D % 2) != (lastDigit % 2);
    }
    // 其他时间：工作日错峰出行规则
    const int weekday = getWeekday(M, D);
    if (weekday == 0 || weekday == 6) {  // 周六或周日不限行
        return false;
    }
    // 使用数组查表法代替switch，更高效
    const int bannedDigits[6][2] = {{-1,-1}, {1,9}, {2,8}, {3,7}, {4,6}, {5,0}};
    return (lastDigit == bannedDigits[weekday][0] || 
            lastDigit == bannedDigits[weekday][1]);
}

signed main(){
    int N;
    cin >> N;
    while (N--) {
        int M, D;
        string plate;
        cin >> M >> D >> plate;
        cout << (isBanned(M, D, plate) ? "Yes" : "No") << '\n';
    }
    return 0;
}