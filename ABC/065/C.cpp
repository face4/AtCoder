#include<iostream>
using namespace std;

typedef long long ll;

ll mod = 1e9 + 7;

int main(){
    int n, m;
    cin >> n >> m;

    ll accum = 0;
    if(abs(n-m) < 2){
        accum = 1;
        for(int i = 2; i <= n; i++){
            accum *= i;
            accum %= mod;
        }
        for(int i = 2; i <= m; i++){
            accum *= i;
            accum %= mod;
        }
    }

    if(n == m)  accum = (2 * accum) % mod;

    cout << accum << endl;

    return 0;
}