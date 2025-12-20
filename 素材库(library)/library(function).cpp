#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

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

bool is_int(double x){
    return floor(x) == x;
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