#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int max_in_line(vector<int> &line){
    int max_val = line[0];
    for(int val : line){
        if(val > max_val){
            max_val = val;
        }
    }
    return max_val;
}

bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i * i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int transform(string s){
    int res = 0;
    for(char c : s){
        res = res * 10 + (c - '0');
    }
    return res;
}

int calculate_length(int x){
    int length = 0;
    while(x){
        length++;
        x /= 10;
    }
    return length;
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
    
    return 0;
}