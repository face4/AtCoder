#include<iostream>
#include<climits>
using namespace std;

#define chmax(a,b)  a = max(a, b)
#define chmin(a,b)  a = min(a, b)

typedef long long ll;

int main(){
    int n, t;
    cin >> n >> t;

    t /= 2;

    ll tmpmin = 1e10, score = -1, a;
    int ans = 1;

    for(int i = 0; i < n; i++){
        cin >> a;
        ll tmpscore = (a-tmpmin) * t;

        if(tmpscore > score){
            score = tmpscore;
            ans = 1;
        }else if(tmpscore == score){
            ans++;
        }
        
        chmin(tmpmin, a);
    }
    
    cout << ans << endl;

    return 0;
}