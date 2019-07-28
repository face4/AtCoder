#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    map<ll,set<ll>> m;
    vector<ll> x(n), y(n);
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];
    for(int i = 0; i < n; i++)  m[x[i]].insert(y[i]);
    int ans = 500;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            ll p = x[j]-x[i], q = y[j]-y[i];
            int tmp = n;
            for(int k = 0; k < n; k++){
                if(m[x[k]-p].count(y[k]-q)) tmp--;
            }
            if(tmp == 0)    tmp++;
            ans = min(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}