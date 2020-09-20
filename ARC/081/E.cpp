// https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd を参考に
// 難しい、まだ100%は理解できていない

#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> v(n+1, vector<int>(26, n));
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            v[i][j] = v[i+1][j];
        }
        v[i][s[i]-'a'] = i;
    }
    vector<int> dp(n+1, 1<<30);
    vector<char> mem(n);
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 26; j++){
            if(v[i][j] == n){
                if(dp[i] == 1)  continue;
                dp[i] = 1;
                mem[i] = (char)('a'+j);
            }else{
                if(dp[i] > dp[v[i][j]+1]+1){
                    dp[i] = dp[v[i][j]+1]+1;
                    mem[i] = (char)('a'+j);
                }
            }
        }
    }
    int pos = 0;
    while(pos < n){
        cout << mem[pos];
        pos = v[pos][mem[pos]-'a']+1;
    }
    cout << endl;
    return 0;
}
