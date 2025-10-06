#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MAX_VAL 100000

signed main(){
    int firstnum = 1;
    int group = 1;
    vector<int> map;
    while(firstnum <= MAX_VAL){
        for(int j = 0; j < group; j++){
            int num = firstnum + j * 3;
            if(num > MAX_VAL) break;
            map.push_back(num);
        }
        if(!map.empty()){
            firstnum = map.back() + 1;
        }else{
            break;
        }
        group++;
    }
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int query;
        cin >> query;
        // 二分查找
        auto it = lower_bound(map.begin(), map.end(), query);
        if(it != map.end() && *it == query){
            cout << (it - map.begin() + 1) << endl;
        } else {
            cout << "Not Found" << endl;
        }
    }
    return 0;
}