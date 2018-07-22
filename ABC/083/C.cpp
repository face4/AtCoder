#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll x, y;
    cin >> x >> y;

    int ans = 1;
    while(x*2 <= y){
        ans++;
        x *= 2;
    }

    cout << ans << endl;
    
    return 0;
}