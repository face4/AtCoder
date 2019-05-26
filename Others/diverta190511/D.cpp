#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll sum = 0, now = 1;
    while(now < n){
        ll d = n/now;
        ll from = now, to = n/d;
        if((n%from)-d >= 0 && ((n%from)-d)%d==0){
            sum += from+(n%from-d)/d;
        }
        now = to+1;
    }
    cout << sum << endl;
    return 0;
}