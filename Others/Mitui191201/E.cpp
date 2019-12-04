#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const int mod = 1000000007;

int main(){
    int n;
    cin >> n;

    ll ans = 1;
    vector<int> v(3, -1);
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        int tim = 0;
        for(int j = 0; j < 3; j++){
            if(x == v[j]+1) tim++;
        }
        if(tim == 0){
            cout << 0 << endl;
            return 0;
        }
        ans *= tim;
        ans %= mod;
        for(int j = 0; j < 3; j++){
            if(x == v[j]+1){
                v[j]++;
                break;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}