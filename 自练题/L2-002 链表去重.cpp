#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

struct node{
    string address;
    int data;
    string next = "-1";
};

signed main(){
    int head, n;
    cin >> head >> n;
    vector<node> list(100005);
    vector<node> deleted_list(100005);
    vector<node> input_list(100005);
    for(int i = 0; i < n; i++){
        node input;
        cin >> input.address >> input.data >> input.next;
        int curr = stoll(input.address);
        input_list[curr].address = input.address;
        input_list[curr].data = input.data;
        input_list[curr].next = input.next;
    }
    int dhead = -1;
    set<int> visited;
    bool find_dhead = false;
    bool find_head = false;
    int input_curr = head;
    int prev, curr, dprev, dcurr;
    node curr_node = input_list[head];
    for(int i = 0; i < n; i++){
        if(visited.count(llabs(curr_node.data))){
            if(!find_dhead){
                dhead = stoll(curr_node.address);
                deleted_list[dhead].address = curr_node.address;
                deleted_list[dhead].data = curr_node.data;
                deleted_list[dhead].next = "-1";
                dprev = dhead;
                find_dhead = true;
            }else{
                dcurr = stoll(curr_node.address);
                deleted_list[dprev].next = curr_node.address;
                deleted_list[dcurr].address = curr_node.address;
                deleted_list[dcurr].data = curr_node.data;
                deleted_list[dcurr].next = "-1";
                dprev = dcurr;
            }
        }else{
            visited.insert(llabs(curr_node.data));
            if(!find_head){
                list[head].address = curr_node.address;
                list[head].data = curr_node.data;
                list[head].next = "-1";
                prev = head;
                find_head = true;
            }else{
                curr = stoll(curr_node.address);
                list[prev].next = curr_node.address;
                list[curr].address = curr_node.address;
                list[curr].data = curr_node.data;
                list[curr].next = "-1";
                prev = curr;
            }
        }
        if(stoll(curr_node.next) == -1) break;// 注意条件
        curr_node = input_list[stoll(curr_node.next)];
    }
    curr = head;
    while(curr != -1){
        cout << list[curr].address << ' ' << list[curr].data << ' ' << list[curr].next << endl;
        curr = stoll(list[curr].next);
    }
    dcurr = dhead;
    while(dcurr != -1){
        cout << deleted_list[dcurr].address << ' ' << deleted_list[dcurr].data << ' ' << deleted_list[dcurr].next << endl;
        dcurr = stoll(deleted_list[dcurr].next);
    }
    return 0;
}