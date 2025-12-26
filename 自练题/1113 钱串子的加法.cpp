#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

string plus_in_base_30(const string& a, const string& b) {
    const string digits = "0123456789abcdefghijklmnopqrst";
    unordered_map<char, int> char_to_value;
    for (int i = 0; i < digits.size(); ++i) {
        char_to_value[digits[i]] = i;
    }

    string result;
    int carry = 0;
    int max_length = max(a.size(), b.size());

    for (int i = 0; i < max_length; ++i) {
        int digit_a = (i < a.size()) ? char_to_value[a[a.size() - 1 - i]] : 0;
        int digit_b = (i < b.size()) ? char_to_value[b[b.size() - 1 - i]] : 0;

        int sum = digit_a + digit_b + carry;
        carry = sum / 30;
        result += digits[sum % 30];
    }

    if (carry > 0) {
        result += digits[carry];
    }

    reverse(result.begin(), result.end());
    return result;
}

signed main(){
    string a, b;
    cin >> a >> b;
    string result = plus_in_base_30(a, b);
    while(result.size() > 1 && result[0] == '0'){
        result = result.substr(1);
    }
    cout << result << endl;
    return 0;
}