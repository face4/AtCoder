#include<iostream>
using namespace std;

int main(){
    int b[101][101] = {}, w[101][101] = {};
    int he, wi;
    cin >> he >> wi;

    for(int i = 1; i <= he; i++){
        for(int j = 1; j <= wi; j++){
            if((i+j)%2) cin >> b[i][j];
            else        cin >> w[i][j];
        }
    }

    for(int i = 1; i <= he; i++){
        for(int j = 1; j <= wi; j++){
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            w[i][j] += w[i-1][j] + w[i][j-1] - w[i-1][j-1];
        }
    }

    int ans = 0;
    for(int i = 1; i <= he; i++){
        for(int j = 1; j <= wi; j++){
            for(int ni = i; ni <= he; ni++){
                for(int nj = j; nj <= wi; nj++){
                    int black = b[ni][nj] - b[i-1][nj] - b[ni][j-1] + b[i-1][j-1];
                    int white = w[ni][nj] - w[i-1][nj] - w[ni][j-1] + w[i-1][j-1];
                    if(black == white)  ans = max(ans, (nj-j+1)*(ni-i+1));
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}