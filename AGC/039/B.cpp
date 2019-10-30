#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool s[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            s[i][j] = c=='1';
        }
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        vector<int> dep(n, 1<<30);
        dep[i] = 1;
        int tmpdep = 1, cnt = 1;
        vector<int> bef({i});
        bool valid = true;
        while(valid && cnt <= n){
            tmpdep++;
            vector<int> next;
            for(int j : bef){
                for(int k = 0; k < n; k++){
                    if(!s[j][k])    continue;
                    if(dep[k] != 1<<30){
                        valid &= abs(dep[k]-dep[j])==1;
                    }else{
                        next.push_back(k);
                        dep[k] = tmpdep;
                    }
                }
            }
            bef = next;
            if(bef.size() == 0) break;
            cnt += bef.size();
        }
        if(valid && cnt == n)   ans = max(ans, tmpdep-1);
    }
    cout << ans << endl;
    return 0;
}