#include<iostream>
using namespace std;
typedef unsigned long long ll;

int main(){
    ll n;
    cin >> n;
    if(n%2 == 1){
        cout << 0 << endl;
        return 0;
    }
    ll five = 0;
    for(ll i = 10; i <= n; i *= 5){
        five += n/i;
    }
    cout << five << endl;
    return 0;
}