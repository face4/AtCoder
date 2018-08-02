#include<iostream>
using namespace std;

int main(){
    int h, w;
    int cost[10][10];
    cin >> h >> w;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> cost[i][j];
        }
    }

    for(int k = 0; k < 10; k++){
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int ans = 0, x;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> x;
            if(x != -1) ans += cost[x][1];
        }
    }

    cout << ans << endl;

    return 0;
}