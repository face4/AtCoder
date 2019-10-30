#include<iostream>
#include<iomanip>
#include<vector>
#include<cstring>
using namespace std;
typedef long long ll;

double dp[70][70][70] = {}, ndp[70][70][70] = {};

int main(){
    int n;
    ll d;
    cin >> n >> d;
    int f[3] = {};
    while(d%2 == 0) d /= 2, f[0]++;
    while(d%3 == 0) d /= 3, f[1]++;
    while(d%5 == 0) d /= 5, f[2]++;
    
    if(d != 1){
        cout << 0 << endl;
        return 0;
    }

    double ans = 0;
    int a[3];
    int s[6][3] = {{0,0,0}, {1,0,0}, {0,1,0}, {2,0,0}, {0,0,1}, {1,1,0}};

    dp[0][0][0] = 1.0;
    for(int t = 0; t < n; t++){
        memset(ndp, 0.0, sizeof(ndp));
        for(a[0] = f[0]; a[0] >= 0; a[0]--){
            for(a[1] = f[1]; a[1] >= 0; a[1]--){
                for(a[2] = f[2]; a[2] >= 0; a[2]--){
                    double base = dp[a[0]][a[1]][a[2]];
                    if(base == 0)   continue;
                    for(int i = 0; i < 6; i++){
                        int b[3];
                        for(int j = 0; j < 3; j++)  b[j] = a[j];
                        for(int j = 0; j < 3; j++){
                            b[j] += s[i][j];
                        }
                        if(b[0] >= f[0] && b[1] >= f[1] && b[2] >= f[2]){
                            ans += base/6;
                        }else{
                            ndp[min(b[0],f[0])][min(b[1],f[1])][min(b[2],f[2])] += base/6;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 70; i++){
            for(int j = 0; j < 70; j++){
                for(int k = 0; k < 70; k++){
                    dp[i][j][k] = ndp[i][j][k];
                }
            }
        }
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
