#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)
typedef long long ll;

int main(){
    vector<int> xaxis, yaxis;
    int n, k;
    cin >> n >> k;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        xaxis.push_back(x[i]);
        yaxis.push_back(y[i]);
    }
    sort(xaxis.begin(), xaxis.end());
    sort(yaxis.begin(), yaxis.end());

    ll ans = LLONG_MAX;
    for(int l = 0; l < n; l++){
        for(int r = l+1; r < n; r++){
            for(int d = 0; d < n; d++){
                for(int u = d+1; u < n; u++){
                    int cnt = 0;
                    for(int k = 0; k < n; k++){
                        if(inRange(x[k], xaxis[l], xaxis[r]) && inRange(y[k], yaxis[d], yaxis[u]))
                            cnt++;
                    }
                    if(cnt >= k){
                        ans = min(ans, ll(xaxis[r]-xaxis[l]) * (yaxis[u]-yaxis[d]));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}