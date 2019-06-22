#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];
    
    int ans = 0;
    for(int i = 0; i <= k; i++){
        // 左からi個取る
        vector<int> take;
        int pos = 0;
        for(int j = 0; j < i && pos < n; j++){
            take.push_back(v[pos]);
            pos++;
        }
        if(pos == n){
            sort(take.begin(), take.end());
            for(int j = 0; j < min(k-i, (int)take.size()); j++){
                take[j] = max(take[j], 0);
            }
            ans = max(ans, accumulate(take.begin(), take.end(),0));
            continue;
        }
        for(int j = 0; j <= k-i; j++){
            // 右からi個取る
            vector<int> ntake = take;
            int rvpos = n-1;
            for(int x = 0; x < j && rvpos >= pos; x++){
                ntake.push_back(v[rvpos]);
                rvpos--;
            }
            sort(ntake.begin(), ntake.end());
            for(int x = 0; x < min(max(k-i-j, 0), (int)ntake.size()); x++){
                ntake[x] = max(ntake[x], 0);
            }
            ans = max(ans, accumulate(ntake.begin(), ntake.end(),0));
        }
    }
    cout << ans << endl;
    return 0;
}