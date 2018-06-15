#include<iostream>
using namespace std;

int main(){
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    bool visit[n+1] = {};
    visit[a] = visit[b] = true;

    int path;
    bool res = true;
    for(int i = 0; i < k; i++){
        cin >> path;
        if(visit[path]) res = false; // 以降、調べる価値無し
        else            visit[path] = true;
    }

    if(res) cout << "YES" << endl;
    else    cout << "NO" << endl;

    return 0;
}