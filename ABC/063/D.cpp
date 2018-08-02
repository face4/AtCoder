#include<iostream>
using namespace std;

typedef long long ll;

int n;
ll a, b, in, h[100000];

bool check(ll x){
    ll needA = 0;
    for(int i = 0; i < n; i++){
        ll residual = h[i] - b*x;
        if(residual > 0)    needA += (residual+a-b-1)/(a-b);
    }
    return needA <= x;
}

int main(){
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++)  cin >> h[i];

    ll r = 0;
    for(int i = 0; i < n; i++)  r += (h[i]+a-1)/a;

    ll l = 1;
    while(l < r){
        ll mid = (l+r)/2;
        if(check(mid))  r = mid;
        else            l = mid;
        if((l+r)/2 == mid)  break;
    }

    cout << r << endl; // 下のように場合分けしなくて良い.これでAC.

    /*
    if(check(l))    cout << l << endl;
    else            cout << r << endl;
    */
    return 0;
}