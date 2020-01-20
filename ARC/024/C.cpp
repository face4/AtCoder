// わざわざ文字列に変換せずにvectorをそのまんまキーと
// して使っちゃってよい(むしろそっちの方が速い)
#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt[26] = {};
    string memo[n];
    set<string> hist;
    for(int i = 0; i < n; i++){
        cnt[s[i]-'a']++;
        if(i >= k){
            cnt[s[i-k]-'a']--;
            hist.insert(memo[i-k]);
        }
        string build = "";
        for(int j = 0; j < 26; j++) build += to_string(cnt[j]), build += "$";
        if(hist.count(build)){
            cout << "YES" << endl;
            return 0;
        }
        memo[i] = build;
    }
    cout << "NO" << endl;
    return 0;
}