#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;

    ll first = min(n, m/2);
    n -= first;
    m -= first*2;

    ll second = m/4;

    cout << first + second << endl;

    return 0;
}