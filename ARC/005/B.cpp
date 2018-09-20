#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int x, y, dx = 0, dy = 0;
    string w;
    cin >> x >> y >> w;
    x--, y--;

    if(count(w.begin(), w.end(), 'R'))    dx = 1;
    if(count(w.begin(), w.end(), 'L'))    dx = -1;
    if(count(w.begin(), w.end(), 'U'))    dy = -1;
    if(count(w.begin(), w.end(), 'D'))    dy = 1;

    char mat[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < 4; i++){
        cout << mat[y][x];
        int nx = x+dx, ny = dy + y;
        if(nx < 0 || 8 < nx)    dx *= -1, nx = x + dx;
        if(ny < 0 || 8 < ny)    dy *= -1, ny = y + dy;
        x = nx, y = ny;
    }
    cout << endl;

    return 0;
}