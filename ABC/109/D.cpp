#include<iostream>
#include<vector>
using namespace std;

#define inRange(x,a,b)  a <= x && x < b
// priority : (weak) left -> up -> right -> down (strong)
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};
vector<vector<int>> ans(250005);

int main(){
    int h, w;
    cin >> h >> w;

    // これで多分REが消える(WAは残る)
    if(h == 1 && w == 1){
        cout << 0 << endl;
        return 0;
    }

    int mat[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(mat[i][j] % 2 == 0)  continue;

            int movetoi, movetoj;
            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(inRange(ni, 0, h) && inRange(nj, 0, w)){
                    movetoi = ni, movetoj = nj;
                    if(mat[ni][nj] % 2 == 1){
                        break;
                    }
                }
            }

            mat[i][j]--;
            mat[movetoi][movetoj]++;

            ans[cnt].push_back(i+1);
            ans[cnt].push_back(j+1);
            ans[cnt].push_back(movetoi+1);
            ans[cnt].push_back(movetoj+1);
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        printf("%d %d %d %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }

    return 0;
}