#include<iostream>
using namespace std;

const int INF = 1<<29;

int main(){
    int n, m;
    int a[1000], b[1000], c[1000];
    int d[100][100];

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }

    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(i == j)  d[i][j] = 0;
            else        d[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        d[a[i]][b[i]] = d[b[i]][a[i]] = min(d[a[i]][b[i]], c[i]);
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][k] == INF || d[k][j] == INF)    continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    int ans = m;
    for(int i = 0; i < m; i++){
        bool use = false;
        for(int s = 0; s < n; s++){
            if(d[s][b[i]] == d[s][a[i]] + c[i]) use = true;
        }
        if(use) ans--;
    }

    cout << ans << endl;

    return 0;
}