#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> v(n+1, vector<int>(26, -2));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            v[i][j] = v[i+1][j];
        }
        v[i][s[i]-'a'] = i;
    }
    string t = "a";
    while(true){
        cout << t << endl;
        // int ind = 0, j;
        // for(j = 0; j < t.length(); j++){
        //     ind = v[ind][t[j]-'a']+1;
        //     if(ind == -1) break;
        // }
        // if(ind == -1){
        //     cout << t << endl;
        //     return 0;
        // }
        bool all = true;
        for(char c : t) all &= c=='z';
        if(all){
            t = string(t.length()+1, 'a');
        }else{
            for(int i = t.length()-1; i >= 0; i--){
                if(t[i] != 'z'){
                    t[i]++;
                    break;
                }else{
                    t[i] = 'a';
                }
            }
        }
    }
}
