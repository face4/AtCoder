#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    ll zero = 0, half = 0;
    for(int i = 1; i <= n; i++){
        if(i%k == 0)    zero++;
        if(k%2 == 0 && i%k == k/2)  half++;
    }

    ll ans;
    if(k % 2 == 0){
        ans = zero*zero*zero + half*half*half;
    }else{
        ans = zero*zero*zero;
    }

    cout << ans << endl;

    return 0;
}