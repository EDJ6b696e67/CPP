#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXP = 200000; // 设定位置上限，避免越界

signed main(){
    int N,K;
    cin>>N>>K;
    
    // 边界条件：农夫在牛前方/同位置，直接后退
    if(N>=K){
        cout<<(N-K)<<endl;
        return 0;
    }
    
    // dist数组：记录到达每个位置的最短步数，-1表示未访问
    vector<int> dist(MAXP+1,-1);
    queue<int> q; // BFS队列，存储待遍历的位置
    
    // 初始化：起始位置步数为0，入队
    dist[N] = 0;
    q.push(N);
    
    while(!q.empty()){
        int x = q.front(); // 取出队首位置
        q.pop();
        
        if(x == K) break; // 找到目标位置，终止遍历
        
        int nx; // 存储下一步位置
        
        // 移动方式1：向后走1步
        nx=x-1;
        if(nx>=0&&dist[nx]==-1){
            dist[nx]=dist[x]+1;
            q.push(nx);
        }
        
        // 移动方式2：向前走1步
        nx=x+1;
        if(nx<=MAXP&&dist[nx]==-1){
            dist[nx]=dist[x]+1;
            q.push(nx);
        }
        
        // 移动方式3：跳跃（x×2）
        nx=x*2;
        if(nx<=MAXP&&dist[nx]==-1){
            dist[nx]=dist[x]+1;
            q.push(nx);
        }
    }
    
    cout<<dist[K]<<endl; // 输出到达K的最短步数
    return 0;
}