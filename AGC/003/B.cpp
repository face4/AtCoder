#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll a, ans = 0, accum = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(a == 0){
            ans += accum/2;
            accum = 0;
        }
        accum += a;
    }
    ans += accum/2;

    cout << ans << endl;

    return 0;
}