#include<iostream>
using namespace std;

int main(){
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int w = tx-sx, h = ty-sy;

    int i;
    for(i = 0; i < h; i++)  cout << "U";
    for(i = 0; i < w; i++)  cout << "R";
    for(i = 0; i < h; i++)  cout << "D";
    for(i = 0; i < w; i++)  cout << "L";
    cout << "L";
    for(i = 0; i < h+1; i++)    cout << "U";
    for(i = 0; i < w+1; i++)    cout << "R";
    cout << "DR";
    for(i = 0; i < h+1; i++)    cout << "D";
    for(i = 0; i < w+1; i++)    cout << "L";
    cout << "U";

    cout << endl;
    return 0;
}