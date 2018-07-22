// 解説AC.難しかった
#include<iostream>
#include<climits>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    int ans = INT_MAX;
    for(int i = 0; i < 4; i++){
        int tmpx , tmpy, change = 0;
        if(i & 1)   tmpx = x;
        else        change++, tmpx = -x;
        if(i & 2)   tmpy = y;
        else        change++, tmpy = -y;
        if(tmpy >= tmpx)    ans = min(tmpy-tmpx+change, ans);
    }
    
    cout << ans << endl;

    return 0;
}