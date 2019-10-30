#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

#define inRange(x,a,b) (a <= x && x < b)
int di[8] = {0,0,1,-1,1,1,-1,-1};
int dj[8] = {1,-1,0,0,1,-1,1,-1};

int dp[800][800];

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    char mat[h][w];
    int si, sj;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'S')    si = i, sj = j;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[si][sj] = 0;
    queue<pii> q;
    q.push({si,sj});
    int ans = 1<<30;
    while(!q.empty()){
        pii p = q.front();  q.pop();
        int i = p.first, j = p.second;
        ans = min(ans, (min({i, h-1-i, j, w-1-j})+k-1)/k);
        if(dp[i][j] == k)   continue;
        for(int k = 0; k < 4; k++){
            int ni = i + di[k], nj = j + dj[k];
            if(!inRange(ni,0,h) || !inRange(nj,0,w) || mat[ni][nj] == '#' || dp[ni][nj] <= dp[i][j]+1)   continue;
            dp[ni][nj] = dp[i][j]+1;
            q.push({ni,nj});
        }
    }
    cout << ans+1 << endl;
}