#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

struct node{
    int address;
    int data;
    int next;
};

vector<node> nodelist(100000);
vector<node> final_list;

void remake_chunks(int head, int k){
    int curr = head;
    for(int i = 0; i < k; i++){
        if(curr == -1) break;
        final_list.pb(nodelist[curr]);
        curr = nodelist[curr].next;
    }
}

signed main(){
    int head, n, k;
    cin >> head >> n >> k;
    vector<int> chunkheads;
    for(int i = 0; i < n; i++){
        int address;
        cin >> address;
        cin >> nodelist[address].data >> nodelist[address].next;
        nodelist[address].address = address;
    }
    int curr = head;
    for(int i = 0; i < nodelist.size(); i++){
        if(curr == -1) break;
        if(i % k == 0){
            chunkheads.pb(curr);
        }
        curr = nodelist[curr].next;
    }
    reverse(chunkheads.begin(), chunkheads.end());
    for(int i = 0; i < chunkheads.size(); i++){
        remake_chunks(chunkheads[i], k);
    }
    for(int i = 0; i < final_list.size(); i++){
        if(i != final_list.size() - 1){
            cout << setw(5) << setfill('0') << final_list[i].address << " " << final_list[i].data << " " << setw(5) << setfill('0') << final_list[i + 1].address << endl;
        } else {
            cout << setw(5) << setfill('0') << final_list[i].address << " " << final_list[i].data << " -1" << endl;
        }
    }
    return 0;
}