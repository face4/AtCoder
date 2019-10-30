// ???
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

bool ok(int i, int j, int k){
    return i<j+k && j<i+k && k<i+j;
}

int main(){
    int n;
    cin >> n;
    vector<int> l(n), cnt(1001, 0);
    for(int i = 0; i < n; i++)  cin >> l[i], cnt[l[i]]++;
    ll ans = 0;
    // 1.7e8
    for(int i = 1; i <= 1000; i++){
        if(cnt[i] == 0) continue;
        for(int j = i+1; j <= 1000; j++){
            if(cnt[j] == 0) continue;
            for(int k = j+1; k <= 1000; k++){
                if(cnt[k] == 0) continue;
                if(ok(i,j,k))   ans += cnt[i]*cnt[j]*cnt[k];
            }
        }
    }
    vector<int> acc(1001, 0);
    for(int i = 1; i <= 1000; i++)  acc[i] = acc[i-1]+cnt[i];
    for(int i = 1; i <= 1000; i++){
        if(cnt[i] >= 2){
            ans += cnt[i]*(cnt[i]-1)/2*(acc[min(1000,2*i-1)]-cnt[i]);
            if(cnt[i] >= 3) ans += (ll)(cnt[i])*(cnt[i]-1)*(cnt[i]-2)/6;
        }
    }
    cout << ans << endl;
    return 0;
}