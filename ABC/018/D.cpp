#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, m, p, q, r, x, y, z;
    cin >> n >> m >> p >> q >> r;
    vector<pair<int,int>> c[n];
    while(r-- > 0){
        cin >> x >> y >> z;
        x--, y--;
        c[x].push_back({y, z});
    }
    int ans = 0;
    for(int i = 0; i < 1<<n; i++){
        vector<int> boys(m, 0);
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    continue;
            cnt++;
            for(pair<int,int> choco : c[j]){
                boys[choco.first] += choco.second;
            }
        }
        if(cnt != p)    continue;
        sort(boys.rbegin(), boys.rend());
        ans = max(ans, accumulate(boys.begin(), boys.begin()+q, 0));
    }
cout << ans << endl;
    return 0;
}