#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int digit(int x){
    int tmp = 0;
    while(x != 0){
        tmp++;
        x /= 10;
    }
    return tmp;
}

int main(){
    ll n;
    cin >> n;

    int ans = 15;
    for(ll i = 1; i <= sqrt(n); i++){
        if(n%i == 0){
            ans = min(ans, max(digit(i), digit(n/i)));
        }
    }

    cout << ans << endl;
    return 0;
}