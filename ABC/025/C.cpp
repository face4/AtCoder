#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> b(2, vector<int>(3,0)), c(3, vector<int>(2,0)), mat(3, vector<int>(3,0));

int dfs(int turn){
    if(turn == 9){
        int score = 0;
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++){
                if(mat[i][j]==mat[i+1][j])  score += b[i][j];
                else                        score -= b[i][j];
            }
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 2; j++){
                if(mat[i][j] == mat[i][j+1])    score += c[i][j];
                else                            score -= c[i][j];
            }
        }
        return score;
    }

    int ret = (turn%2 == 0 ? -(1<<30) : 1<<30);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(mat[i][j] != 0)  continue;
            if(turn%2 == 0){
                mat[i][j] = 1;
                ret = max(ret, dfs(turn+1));
            }else{
                mat[i][j] = -1;
                ret = min(ret, dfs(turn+1));
            }
            mat[i][j] = 0;
        }
    }
    return ret;
}

int main(){
    int sum = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cin >> b[i][j];
            sum += b[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            cin >> c[i][j];
            sum += c[i][j];
        }
    }
    int ans = dfs(0);
    cout << (sum+ans)/2 << endl;
    cout << (sum-ans)/2 << endl;
    return 0;
}