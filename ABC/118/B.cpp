#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int cnt[31] = {};
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;

        int p;
        while(k-- > 0){
            cin >> p;
            cnt[p]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= m; i++) if(cnt[i] == n) ans++;

    cout << ans << endl;
    
    return 0;
}