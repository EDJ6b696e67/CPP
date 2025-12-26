#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl "\n"

struct character{
    char mean;
    vector<string> form_of_character;
    character(): form_of_character(7) {}
};

character ch[26];

void output_word(const string &word){
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < word.size(); j++){
            int index = word[j] - 'A';
            cout << ch[index].form_of_character[i];
            if(j != word.size() - 1) cout << " ";
        }
        if(i != 6) cout << endl;
    }
}

signed main(){
    for(int i = 0; i < 26; i++){
        ch[i].mean = 'A' + i;
        for(int j = 0; j < 7; j++){
                cin >> ch[i].form_of_character[j];
        }
    }
    string sentence;
    getchar();
    getline(cin, sentence);
    vector<string> word;
    int begin_of_word = 0;
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] < 'A' || sentence[i] > 'Z'){
            word.pb(sentence.substr(begin_of_word, i - begin_of_word));
            begin_of_word = i + 1;
        }
    }
    if(begin_of_word < sentence.size()){
        word.pb(sentence.substr(begin_of_word, sentence.size() - begin_of_word));
    }
    bool first_word = true;
    for(int i = 0; i < word.size(); i++){
        if(word[i][0] < 'A' || word[i][0] > 'Z') continue;
        if(!first_word) cout << endl << endl;
        first_word = false;
        output_word(word[i]);
    }
    return 0;
}