#include<iostream>
#include<cmath>
using namespace std;

double dist(int a, int b, int c, int d){
    return pow(c-a,2.0) + pow(d-b, 2.0);
}

int main(){
    int x1, y1, r, x2, y2, x3, y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

    bool a = x2 <= x1-r && x1+r <= x3 && y2 <= y1-r && y1+r <= y3;
    bool b = dist(x1,y1,x2,y2) <= r*r && dist(x1,y1,x2,y3) <= r*r &&
             dist(x1,y1,x3,y2) <= r*r && dist(x1,y1,x3,y3) <= r*r;

    if(a)   cout << "NO" << endl;
    else    cout << "YES" << endl;

    if(b)   cout << "NO" << endl;
    else    cout << "YES" << endl;

    return 0;
}