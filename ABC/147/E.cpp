#include<iostream>
using namespace std;

bool dp[80][80][12805] = {};
#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int h, w;
    cin >> h >> w;
    int a[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int x;  cin >> x;
            a[i][j] -= x;
            a[i][j] = abs(a[i][j]);
        }
    }
    dp[0][0][6400+a[0][0]] = dp[0][0][6400-a[0][0]] = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            for(int k = 0; k <= 12804; k++){
                if(!dp[i][j][k])    continue;
                if(i+1 < h){
                    if(inRange(k+a[i+1][j], 0, 12804))   dp[i+1][j][k+a[i+1][j]] = true;
                    if(inRange(k-a[i+1][j], 0, 12804))   dp[i+1][j][k-a[i+1][j]] = true;
                }
                if(j+1 < w){
                    if(inRange(k+a[i][j+1], 0, 12804))   dp[i][j+1][k+a[i][j+1]] = true;
                    if(inRange(k-a[i][j+1], 0, 12804))   dp[i][j+1][k-a[i][j+1]] = true;
                }
            }
        }
    }
    for(int i = 0; i <= 6400; i++){
        if(dp[h-1][w-1][6400+i] || dp[h-1][w-1][6400-i]){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}