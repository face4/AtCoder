#include<iostream>
#include<map>
#include<vector>
#include<cctype>
using namespace std;

int main(){
    map<char, char> dict;
    dict['b'] = '1';
    dict['c'] = '1';
    dict['d'] = '2';
    dict['w'] = '2';
    dict['t'] = '3';
    dict['j'] = '3';
    dict['f'] = '4';
    dict['q'] = '4';
    dict['l'] = '5';
    dict['v'] = '5';
    dict['s'] = '6';
    dict['x'] = '6';
    dict['p'] = '7';
    dict['m'] = '7';
    dict['h'] = '8';
    dict['k'] = '8';
    dict['n'] = '9';
    dict['g'] = '9';
    dict['z'] = '0';
    dict['r'] = '0';

    int n;
    cin >> n;
    vector<string> ans;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        string res = "";
        for(int j = 0; j < s.length(); j++){
            if(dict.count(tolower(s[j])))    res += dict[tolower(s[j])];
        }
        if(res != "")   ans.push_back(res);
    }

    for(int i = 0; i < ans.size(); i++){
        if(i)   cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}