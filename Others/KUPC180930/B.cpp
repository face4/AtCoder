#include<iostream>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int h, w;
char mat[10][10];
string ans = "";

void dfs(int i, int j, string s){
    if(i == 0){
        ans = s;
        return;
    }

    if(inRange(j-1, 0, w) && mat[i-1][j-1] == '.'){
        s += "L";
        dfs(i-1, j-1, s);
        s.pop_back();
    }

    if(mat[i-1][j] == '.'){
        s += "S";
        dfs(i-1, j, s);
        s.pop_back();
    }

    if(inRange(j+1, 0, w) && mat[i-1][j+1] == '.'){
        s += "R";
        dfs(i-1, j+1, s);
        s.pop_back();
    }
}

int main(){
    cin >> h >> w;

    int y, x;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == 's')    y = i, x = j;
        }
    }

    dfs(y, x, "");

    if(ans != "")   cout << ans << endl;
    else            cout << "impossible" << endl;

    return 0;
}