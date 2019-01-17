#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    vector<vector<bool>> dp(2, vector<bool>(16002, 0));
    vector<int> v[2];
    dp[0][8001] = dp[1][8001] = true;

    int tmp = 0, dir = 0;
    for(char x : s){
        if(x == 'F'){
            tmp++;
        }else{
            v[dir].push_back(tmp);
            dir = 1-dir;
            tmp = 0;
        }
    }
    if(tmp) v[dir].push_back(tmp);

    // ロボットは最初x軸正の方向を向いている！
    if(s[0] == 'F'){
        dp[0][8001] = false;
        dp[0][8001+v[0][0]] = true;
        v[0].erase(v[0].begin());
    }
    
    // 最悪4000*16000=6.4e7
    for(int i = 0; i < 2; i++){
        for(int val : v[i]){
            if(val == 0)    continue;
            vector<bool> next(16002, 0);
            for(int j = 0; j < 16002; j++){
                if(dp[i][j])    next[j-val] = next[j+val] = true;
            }
            dp[i] = next;
        }
    }

    cout << ((dp[0][x+8001]&&dp[1][y+8001]) ? "Yes" : "No") << endl;

    return 0;
}
