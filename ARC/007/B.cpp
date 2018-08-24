#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int cd[n];
    for(int i = 0; i < n; i++)    cd[i] = i+1;

    int now = 0, next, pos;
    for(int i = 0; i < m; i++){
        cin >> next;
        for(pos = 0;;pos++) if(cd[pos] == next) break;
        swap(now, cd[pos]);
    }

    for(int x : cd) cout << x << endl;

    return 0;
}