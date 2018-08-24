#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll x[n], y[n];
    for(int i = 0; i < n; i++)  cin >> x[i] >> y[i];

    int ans = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                ll a = x[j] - x[i];
                ll b = y[j] - y[i];
                ll c = x[k] - x[i];
                ll d = y[k] - y[i];
                ll tmp = a*d - b*c;
                if(tmp != 0 && abs(tmp) % 2 == 0)   ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}