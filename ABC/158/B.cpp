#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    cout << n/(a+b)*a+min(n%(a+b), a) << endl;
    return 0;
}