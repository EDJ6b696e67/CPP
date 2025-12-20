#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct node{
    int address;
    int before;
    int data;
    int next;
};

vector<node> nodelist(100000);
vector<node> final_list;

void merger_list_as_custom_mode(int head_of_first_list, int end_of_second_list){
    int curr_1 = head_of_first_list;
    int curr_2 = end_of_second_list;
    while(curr_1 != -1 || curr_2 != -1){
        if(curr_1 != -1){
            final_list.push_back(nodelist[curr_1]);
            curr_1 = nodelist[curr_1].next;
        }
        if(curr_1 != -1){
            final_list.push_back(nodelist[curr_1]);
            curr_1 = nodelist[curr_1].next;
        }
        if(curr_2 != -1){
            final_list.push_back(nodelist[curr_2]);
            curr_2 = nodelist[curr_2].before;
        }
    }
}

signed main(){
    int head_1, head_2, n;
    cin >> head_1 >> head_2 >> n;
    for(int i = 0; i < n; i++){
        int address;
        cin >> address;
        cin >> nodelist[address].data >> nodelist[address].next;
        nodelist[address].address = address;
        nodelist[address].before = -1;
    }

    int length_1 = 0;
    int curr = head_1;
    int prev = -1;
    while(curr != -1){
        nodelist[curr].before = prev;
        prev = curr;
        curr = nodelist[curr].next;
        length_1++;
    }
    int end_1 = prev;

    int length_2 = 0;
    curr = head_2;
    prev = -1;
    while(curr != -1){
        nodelist[curr].before = prev;
        prev = curr;
        curr = nodelist[curr].next;
        length_2++;
    }
    int end_2 = prev;

    if(length_1 > length_2){
        merger_list_as_custom_mode(head_1, end_2);
    } else {
        merger_list_as_custom_mode(head_2, end_1);
    }

    for(int i = 0; i < final_list.size(); i++){
        if(i != final_list.size() - 1){
            cout << setw(5) << setfill('0') << final_list[i].address << " " << final_list[i].data << " " << setw(5) << setfill('0') << final_list[i+1].address << endl;
        } else {
            cout << setw(5) << setfill('0') << final_list[i].address << " " << final_list[i].data << " -1" << endl;
        }
    }

    return 0;
}