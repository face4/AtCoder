#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll sum = -n;
    for(ll i = 1; i <= sqrt(n); i++){
        if(n%i) continue;
        sum += i + n/i;
        if(i*i == n)    sum -= i;
    }

    if(sum == n)    cout << "Perfect" << endl;
    if(sum < n)     cout << "Deficient" << endl;
    if(sum > n)     cout << "Abundant" << endl;

    return 0;
}