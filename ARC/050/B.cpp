#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll r, b, x, y;
    cin >> r >> b >> x >> y;

    ll low = 0, high = min(r,b)+1;

    while(high-low > 1){
        ll mid = (low+high)/2;
        ll make = (r-mid)/(x-1) + (b-mid)/(y-1);
        if(make < mid){
            high = mid;
        }else{
            low = mid;
        }
    }

    cout << low << endl;

    return 0;
}