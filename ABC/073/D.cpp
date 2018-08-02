#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

const int INF = 1<<25;
int path[200][200] = {};

int main(){
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            if(i == j)  continue;
            path[i][j] = INF;
        }
    }

    int n, m, R;
    cin >> n >> m >> R;
    
    int r[R];
    for(int i = 0; i < R; i++)  cin >> r[i];
    for(int i = 0; i < R; i++)  r[i]--;
    sort(r, r+R);

    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        path[a][b] = path[b][a] = c;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(path[i][k] == INF || path[k][j] == INF)  continue;
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }

    int ans = INT_MAX;
    do{
        int tmp = 0;
        for(int i = 0; i < R-1; i++){
            tmp += path[r[i]][r[i+1]];
        }
        ans = min(ans, tmp);
    }while(next_permutation(r, r+R));

    cout << ans << endl;

    return 0;
}