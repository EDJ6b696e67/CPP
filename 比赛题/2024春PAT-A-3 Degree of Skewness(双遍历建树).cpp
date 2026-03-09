#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb emplace_back
#define endl "\n"

struct tree_node{
    int val;
    tree_node *left;
    tree_node *right;
    tree_node(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<int> post_order;
vector<int> in_order;
unordered_map<int, int> in_order_map;

tree_node* create_tree(int post_l, int post_r, int in_l, int in_r){
    if(post_l >= post_r) return nullptr;
    int root_val = post_order[post_r - 1];
    tree_node* root = new tree_node(root_val);
    int root_index_of_in_order = in_order_map[root_val];
    int left_size = root_index_of_in_order - in_l;
    root -> left = create_tree(post_l, post_l + left_size, in_l, root_index_of_in_order);
    root -> right = create_tree(post_l + left_size, post_r - 1, root_index_of_in_order + 1, in_r);
    return root;
}

int nl = 0, nr = 0;

void calculate_degree_of_skewness(tree_node* nodes){
    if(!nodes) return;
    if(nodes -> left && !nodes -> right) nl++;
    if(!nodes -> left && nodes -> right) nr++;
    calculate_degree_of_skewness(nodes -> left);
    calculate_degree_of_skewness(nodes -> right);
}

signed main(){
    int n;
    cin >> n;
    post_order.resize(n);
    in_order.resize(n);
    for(int i = 0; i < n; i++) cin >> post_order[i];
    for(int i = 0; i < n; i++){
        cin >> in_order[i];
        in_order_map[in_order[i]] = i;
    }
    tree_node* tree = create_tree(0, n, 0, n);
    calculate_degree_of_skewness(tree);
    cout << nl - nr << " = " << nl << " - " << nr << endl;
    return 0;
}