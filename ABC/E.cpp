#include<iostream>
using namespace std;
typedef long long ll;

ll dp[101][2][5] = {};

ll f(string s, int K){
    int n = s.length();
    for(int i = 0; i < n; i++){
        // success
        for(int j = 0; j < 2; j++){
            for(int k = 0; k <= K; k++){
                if(dp[i][j][k] == 0)    continue;
                for(int val = 0; val < 10; val++){
                    if(j==0 && val > s[i]-'0')  break;
                    if(k==0 && val != 0)    continue;
                    int ni = i+1;
                    int nj = j | (val < s[i]-'0');
                    int nk = val!=0 ? k-1 : k;
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
        // start
        for(int val = 1; val < 10; val++){
            if(i == 0 && val > s[i]-'0')    break;
            int less = !(i==0 && s[i]-'0'==val);
            dp[i+1][less][K-1]++;
        }
    }
    ll ret = 0;
    for(int j = 0; j < 2; j++){
        ret += dp[n][j][0];
    }
    return ret;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    cout << f(s, k) << endl;
    return 0;
}
