#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
    // 读取旅客人数 n 和转盘容量 m
    int n, m;
    cin >> n >> m;
    
    // 用于存放行李标签，该序列表示行李送上转盘的顺序（标签确保唯一且长度为8）
    vector<string> id_case(n);
    // 用于存放旅客手持的行李标签，该序列代表旅客排队顺序
    vector<string> id_passenger(n);
    
    // 读取每件行李的标签
    for(int i = 0; i < n; i++){
        cin >> id_case[i];
    }
    // 读取每位旅客持有的行李标签
    for(int i = 0; i < n; i++){
        cin >> id_passenger[i];
    }
    
    // 使用集合存储所有行李标签，便于判断某个标签是否存在，即行李是否丢失
    unordered_set<string> allcases(id_case.begin(), id_case.end());
    
    // 初始化转盘队列（模拟转盘），最开始放置 min(n, m) 件行李
    deque<string> wheel;
    int putin = min(n, m);
    for(int i = 0; i < putin; i++){
        wheel.push_back(id_case[i]);
    }
    
    // 紧接着需要放入转盘的行李下标
    int next_case = putin;
    
    // 初始化旅客队列，将每位旅客持有的行李标签依次入队
    deque<string> queue_p;
    for(auto &q : id_passenger){
        queue_p.push_back(q);
    }
    
    // 初始化时间计数器，每一步耗时1分钟
    int time = 0;
    
    // 模拟过程：循环直到所有旅客都处理完毕
    while(!queue_p.empty()){
        // 取出队首旅客的行李标签
        string midid = queue_p.front();
        queue_p.pop_front();
        
        // 判断该旅客的标签是否在所有行李中：若不在说明该行李丢失
        if(allcases.find(midid) == allcases.end()){
            cout << midid << " is lost!" << endl;
            time++; // 丢失的情况也占用1分钟
            // 此旅客直接离队，不再等待
            continue;
        }
        
        // 在转盘中查找与旅客标签匹配的行李
        auto case_finding = find(wheel.begin(), wheel.end(), midid);
        if(case_finding != wheel.end()){
            // 如果找到匹配行李，说明旅客成功取到行李，则从转盘中移除该行李
            wheel.erase(case_finding);
            // 若还有剩余的行李未放入转盘，则将下一件行李放入转盘
            if(next_case < n){
                wheel.push_back(id_case[next_case]);
                next_case++;
            }
        }else{
            // 如果转盘中暂时无匹配行李，则该旅客到队尾等待下一轮机会
            queue_p.push_back(midid);
        }
        // 每进行一次操作，耗时增加1分钟
        time++;
    }
    
    // 所有旅客处理完毕后，输出总共耗费的时间
    cout << time << endl;
    
    return 0;
}