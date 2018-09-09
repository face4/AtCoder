#include<iostream>
using namespace std;

bool red[100001] = {};
int ball[100001] = {};

int main(){
    int n, m, x, y;
    cin >> n >> m;
    red[1] = true;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        ball[x]--;
        ball[y]++;
        if(red[x])  red[y] = true;
        if(ball[x] == -1)   red[x] = false;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) if(red[i])  ans++;

    cout << ans << endl;

    return 0;
}