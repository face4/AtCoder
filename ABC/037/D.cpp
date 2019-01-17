#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int dx[8] = {0,0,1,-1,1,1,-1,-1};
int dy[8] = {1,-1,0,0,1,-1,1,-1};

const int mod = 1e9+7;

int main(){
    int h, w;
    cin >> h >> w;

    int a[h][w], dp[h][w];
    vector<pair<int,pair<int,int>>> v;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf("%d", &a[i][j]);
            dp[i][j] = 1;
            v.push_back({a[i][j],{i,j}});
        }
    }

    sort(v.begin(), v.end());

    for(auto p : v){
        pair<int,int> pos = p.second;
        int i = pos.first, j = pos.second;
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k], nj = j + dy[k];
            if(inRange(ni,0,h) && inRange(nj,0,w) && a[ni][nj] > a[i][j]){
                dp[ni][nj] = (dp[ni][nj]+dp[i][j])%mod;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans = (ans + dp[i][j])%mod;
        }
    }

    cout << ans << endl;

    return 0;
}