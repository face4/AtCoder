#include<iostream>
#include<queue>
#include<vector>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)
int di[4] = {-1, 1, 0, 0};
int dj[4] = {0, 0, 1, -1};

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    char mat[h][w];
    int si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;
    si--, sj--, gi--, gj--;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 1<<30));
    dp[si][sj] = 0;
    queue<pair<int,int>> q;
    q.push({si,sj});
    while(!q.empty()){
        pair<int,int> p = q.front();    q.pop();
        int i = p.first, j = p.second;
        if(i == gi && j == gj){
            cout << dp[i][j] << endl;
            return 0;
        }
        for(int z = 0; z < 4; z++){
            for(int d = 1; d <= k; d++){
                int ni = i+di[z]*d, nj = j+dj[z]*d;
                if(!inRange(ni, 0, h) || !inRange(nj, 0, w))  break;
                if(mat[ni][nj] == '@')  break;
                if(dp[i][j] > dp[ni][nj])   break;
                if(dp[i][j]+1 < dp[ni][nj]){
                    dp[ni][nj] = dp[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}