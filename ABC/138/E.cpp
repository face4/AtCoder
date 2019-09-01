#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    string s, t;
    cin >> s >> t;
    vector<int> app[26];
    for(int i = 0; i < s.length(); i++){
        app[s[i]-'a'].push_back(i);
    }
    ll cur = 0, lap = 0;
    for(int i = 0; i < t.length(); i++){
        int tmp = t[i]-'a';
        int ind = lower_bound(app[tmp].begin(), app[tmp].end(), cur) - app[tmp].begin();
        if(ind == app[tmp].size()){
            lap++;
            cur = 0;
            ind = lower_bound(app[tmp].begin(), app[tmp].end(), cur) - app[tmp].begin();
            if(ind == app[tmp].size()){
                cout << -1 << endl;
                return 0;
            }
        }
        cur = app[tmp][ind]+1;
        if(cur >= s.length())   lap++, cur = 0;
    }
    cout << lap*(ll)(s.length()) + cur << endl;
    return 0;
}