#include<iostream>
using namespace std;

const int INF = 1<<21;

int main(){
    int n, m;
    cin >> n >> m;

    int dis[n+1][n+1];
    for(int i = 0; i < n+1; i++){
        for(int j = 0; j < n+1; j++){
            dis[i][j] = INF;
        }
    }
    for(int i = 0; i < n+1; i++)    dis[i][i] = 0;

    int a, b;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        dis[a][b] = dis[b][a] = 1;
    }

    // wf
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(dis[i][k] == INF || dis[k][j] == INF)    continue;
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int ans = 0;
        for(int j = 1; j <= n; j++){
            if(dis[i][j] == 2)  ans++;
        }
        cout << ans << endl;
    }

    return 0;
}