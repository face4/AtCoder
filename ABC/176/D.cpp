#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;
#define inRange(x,a,b) (a <= x && x < b)

int main(){
    int h, w;
    cin >> h >> w;
    int si, sj, gi, gj;
    cin >> si >> sj >> gi >> gj;
    si--, sj--, gi--, gj--;
    char mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }
    vector<vector<int>> dp(h, vector<int>(w, 1<<30));
    bool done[h][w];
    memset(done, 0, sizeof(done));
    deque<pii> q;
    q.push_front({si, sj});
    dp[si][sj] = 0;
    while(!q.empty()){
        pii p = q.front();  q.pop_front();
        int i = p.first, j = p.second;
        if(done[i][j])  continue;
        done[i][j] = true;
        for(int di = -2; di <= 2; di++){
            for(int dj = -2; dj <= 2; dj++){
                int ni = i+di, nj = j+dj;
                if(!inRange(ni,0,h) || !inRange(nj,0,w) || mat[ni][nj]=='#')    continue;
                if(abs(di)+abs(dj)==1 && dp[ni][nj] > dp[i][j]){
                    dp[ni][nj] = dp[i][j];
                    q.push_front({ni,nj});
                }else if(dp[ni][nj] > dp[i][j]+1){
                    dp[ni][nj] = dp[i][j]+1;
                    q.push_back({ni,nj});
                }
            }
        }
    }
    cout << (dp[gi][gj]==1<<30 ? -1 : dp[gi][gj]) << endl;
    return 0;
}