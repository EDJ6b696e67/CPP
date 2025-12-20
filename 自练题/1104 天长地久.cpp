#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

struct node{
    int n, custom_num;
};

bool cmp(node a, node b){
    if(a.n != b.n) return a.n < b.n;
    return a.custom_num < b.custom_num;
}

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int sum_per_digit(int x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

signed main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cout << "Case " << i + 1 << endl;
        int k, m;
        cin >> k >> m;
        if(m > 9 * k || m < 18){
            cout << "No Solution" << endl;
            continue;
        }
        vector<node> A;
        int num_of_digits = pow(10, k - 2);
        for(int i = num_of_digits / 10; i < num_of_digits; i++){
            int sum_1 = 18;
            int sum_2 = 0;
            int custom_num_1 = i;
            int custom_num_2 = i + 1;
            sum_1 += sum_per_digit(custom_num_1);
            sum_2 += sum_per_digit(custom_num_2);
            int gcd_val = __gcd(m, sum_2);
            if(sum_1 == m && is_prime(gcd_val) && gcd_val > 2){
                node temp;
                temp.n = sum_2;
                temp.custom_num = custom_num_1;
                A.push_back(temp);
            }
        }
        if(A.empty()){
            cout << "No Solution" << endl;
            continue;
        }
        sort(A.begin(), A.end(), cmp);
        for(const auto& item : A){
            cout << item.n << " " << item.custom_num << "99" << endl;
        }
    }
    return 0;
}