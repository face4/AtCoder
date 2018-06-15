#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll taka, aoki;
    cin >> taka >> aoki;

    ll t, a;
    for(int i = 1; i < n; i++){
        cin >> t >> a;
        ll times = max(taka/t+(taka%t!=0), aoki/a+(aoki%a!=0));

        taka = times*t;
        aoki = times*a;
   }

    cout << taka+aoki << endl;
    return 0;
}