#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    int c[n], a[n][m];
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0; j < m; j++)  cin >> a[i][j];
    }
    int ret = 1<<30;
    for(int s = 1; s < 1<<n; s++){
        vector<int> tmp(m, 0);
        int score = 0;
        for(int i = 0; i < n; i++){
            if((s>>i&1) == 0) continue;
            score += c[i];
            for(int j = 0; j < m; j++)  tmp[j] += a[i][j];
        }
        bool ok = true;
        for(int j = 0; j < m; j++)  ok &= tmp[j] >= x;
        if(ok)  ret = min(ret, score);
    }
    cout << (ret==1<<30 ? -1 : ret) << endl;
    return 0;
}