#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    int n;
    string s;
    cin >> n >> s;

    if(s[0] == 'W' || s.back() == 'W'){
        cout << 0 << endl;
        return 0;
    }

    n *= 2;

    ll ans = 1, tmp = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == 'W'){
            if(tmp % 2 == 0){
                ans *= tmp;
                ans %= mod;
                tmp--; 
            }else{
                tmp++;
            }
        }else{
            if(tmp % 2 == 1){
                ans *= tmp;
                ans %= mod;
                tmp--;
            }else{
                tmp++;
            }
        }
    }
    ll fact = 1;
    for(ll i = 1; i <= n/2; i++)    fact = fact*i%mod;
    if(tmp != 0)    cout << 0 << endl;
    else            cout << ans*fact%mod << endl;
    return 0;
}