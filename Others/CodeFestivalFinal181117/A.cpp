#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    // memory...10^8
    vector<vector<int>> v(n+1, vector<int>(1001, 0));

    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &c);
        v[b][c-1000]++;
        v[a][c-1000]++;
    }

    // time...2 * 10^7
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 269; j++){
            ans += v[i][j] * v[i][540-j];
        }
        ans += v[i][270] * (v[i][270]-1) / 2;
    }

    cout << ans << endl;

    return 0;
}