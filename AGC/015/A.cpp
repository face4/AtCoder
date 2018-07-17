#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;

    if((n < 2 && a != b) || a > b){
        cout << 0 << endl;
    }else{
        cout << b*(n-2) - a*(n-2) + 1<< endl;
    }

    return 0;
}