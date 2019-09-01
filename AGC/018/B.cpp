// 解説AC
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    int ans = n;
    vector<bool> used(m, 0);
    for(int s = 0; s+1 < m; s++){
        vector<int> cnt(m, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(used[a[i][j]])   continue;
                cnt[a[i][j]]++;
                break;
            }
        }
        int ma = 0, ind = -1;
        for(int i = 0; i < m; i++){
            if(cnt[i] > ma){
                ma = cnt[i];
                ind = i;
            }
        }
        ans = min(ans, ma);
        used[ind] = true;
    }
    cout << ans << endl;
    return 0;
}