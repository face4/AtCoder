#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a, k;
    cin >> a >> k;

    if(k == 0){
        cout << 2000000000000ll - a << endl;
    }else{
        ll now = a;
        int day = 0;
        while(now < 2e12){
            day++;
            now = (1+k)*now + 1;
        }
        cout << day << endl;
    }

    return 0;
}