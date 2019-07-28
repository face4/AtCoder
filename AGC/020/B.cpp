#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    int k;
    cin >> k;
    vector<ll> v(k);
    for(int i = 0; i < k; i++)  cin >> v[i];
    if(v[k-1] != 2){
        cout << -1 << endl;
        return 0;
    }
    ll low = 2, high = 3;
    for(int i = k-2; i >= 0; i--){
        if(high < v[i]){
            cout << -1 << endl;
            return 0;
        }
        high = high / v[i] * v[i] + v[i]-1;
        low = (low + v[i] - 1) / v[i] * v[i];
    }
    if(low > high)  cout << -1 << endl;
    else            cout << low << " " << high << endl;
    return 0;
}