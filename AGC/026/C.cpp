#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n >> s;
    string a = s.substr(0, n), b = s.substr(n);
    reverse(b.begin(), b.end());
    map<string,map<string,ll>> m;
    for(int i = 0; i < 1<<n; i++){
        string c = "", d = "";
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    c += a[j];
            else            d += a[j];
        }
        m[c][d]++;
    }
    ll ans = 0;
    for(int i = 0; i < 1<<n; i++){
        string c = "", d = "";
        for(int j = 0; j < n; j++){
            if((i>>j)&1)    c += b[j];
            else            d += b[j];
        }
        ans += m[c][d];
    }
    cout << ans << endl;
    return 0;
}