// 解説AC.難しかった.
#include<iostream>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    int ans;
    if(x < y)   ans = min(y-x, abs(y+x)+1);
    else        ans = min(x-y+2, abs(y+x)+1);
    cout << ans << endl;
    return 0;
}