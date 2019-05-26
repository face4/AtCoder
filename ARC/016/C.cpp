#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<double> p(m);
    vector<vector<double>> v(m, vector<double>(n,0));
    for(int i = 0; i < m; i++){
        int k;
        cin >> k >> p[i];
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            v[i][--x] = y/100.0;
        }
    }
    vector<double> dp(1<<n);
    // dp[i] := アイドル集合iを入手するために必要な金額の期待値
    for(int i = 1; i < 1<<n; i++){
        dp[i] = 1<<30;
        // どのくじを引いて状態iに至ったか？(くじを全探索)
        for(int j = 0; j < m; j++){
            double valid = 0.0; // くじjを引いて(iに含まれる)アイドルを入手する確率
            for(int k = 0; k < n; k++){
                if((i>>k)&1)    valid += v[j][k];
            }
            if(valid == 0.0)    continue; // くじjを引いて状態iに到達することが起こり得ない
            double val = 0;
            for(int k = 0; k < n; k++){
                if(((i>>k)&1) == 0) continue;
                // dp[i^(1<<k)] ... 状態iからアイドルkを抜いたアイドル集合を入手するために必要な金額の期待値
                // (p[j]/valid) ... くじjのみを引き続けて所持していないアイドルを引き当てるまでにかかる金額の期待値
                // (v[j][k]/valid) ... 所持していないアイドルを引いたときに、そのアイドルがkである確率(割合、重みづけの項だと思えば良い)
                val += (dp[i^(1<<k)]+p[j]/valid)*(v[j][k]/valid);
            }
            dp[i] = min(dp[i], val);
        }
    }
    cout << fixed << setprecision(12) << dp.back() << endl;
    return 0;
}