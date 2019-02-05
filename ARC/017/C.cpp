// 半分全列挙
#include<iostream>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    int n, x;
    cin >> n >> x;

    int w[n];
    for(int i = 0; i < n; i++)  cin >> w[i];

    int n1 = n/2;
    map<ll,ll> cnt;
    for(int i = 0; i < 1<<n1; i++){
        ll tmpw = 0;
        for(int j = 0; j < n1; j++){
            if((i>>j)&1)    tmpw += w[j];
        }
        cnt[tmpw]++;
    }

    ll ans = 0;
    for(int i = 0; i < 1<<(n-n1); i++){
        ll tmpw = 0;
        for(int j = 0; j < n-n1; j++){
            if((i>>j)&1)    tmpw += w[n1+j];
        }
        if(tmpw > x)    continue;
        ans += cnt[x-tmpw];
    }

    cout << ans << endl;

    return 0;
}