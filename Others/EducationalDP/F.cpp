#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int h = s.length(), w = t.length();

    int dp[h+1][w+1];
    memset(dp, 0, sizeof(dp));
    pair<int,int> rev[h+1][w+1];

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i] == t[j]){
                dp[i+1][j+1] = dp[i][j]+1;
                rev[i+1][j+1] = {-1,-1};
            }
            if(dp[i+1][j+1] < dp[i][j+1])   dp[i+1][j+1] = dp[i][j+1], rev[i+1][j+1] = {-1, 0};
            if(dp[i+1][j+1] < dp[i+1][j])   dp[i+1][j+1] = dp[i+1][j], rev[i+1][j+1] = {0, -1};
        }
    }

    string res = "";
    int hh = h, ww = w;
    while(hh > 0 && ww > 0){
        pair<int,int> p = rev[hh][ww];
        if(p.first+p.second == -2){
            res += s[hh-1];
        }else if(p.first+p.second == 0){
            break;
        }
        hh += p.first, ww += p.second;
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return 0;
}