#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

signed main(){
    set<int> numbers;
    int x, y;
    cin >> x >> y;
    numbers.insert(x);
    numbers.insert(y);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> input(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> input[i][j];
        }
    }

    vector<bool> game_over(n, false);
    for(int i = 0; i < m; i++){

        int game_over_id = -1;
        for(int j = 0; j < n; j++){
            if(!game_over[j]){
                int get_number = input[j][i];

                bool valid = false;
                for(auto num : numbers){
                    if(numbers.find(get_number + num) != numbers.end()){
                        valid = true;
                        break;
                    }
                }

                if(valid && numbers.find(get_number) == numbers.end()){
                    numbers.insert(get_number);
                }else{
                    game_over[j] = true;
                    game_over_id = j + 1;
                    cout << "Round #" << i + 1 << ": " << game_over_id << " is out." << endl;
                }
            }
        }
    }

    vector<int> winners;
    for(int i = 0; i < n; i++){
        if(!game_over[i]){
            winners.pb(i + 1);
        }
    }

    if(winners.empty()){
        cout << "No winner." << endl;
    }else{
        cout << "Winner(s):";
        for(auto winner : winners){
            cout << " " << winner;
        }
        cout << endl;
    }

    return 0;
}