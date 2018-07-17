#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n, p;
    cin >> n >> p;

    int a[n];
    bool odd = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]%2 == 1) odd = true;
    }

    if(odd == false && p == 0){
        ll ans = 1;
        for(int i = 0; i < n; i++)  ans *= 2;
        cout << ans << endl;
    }else if(odd == false && p == 1){
        cout << 0 << endl;
    }else{
        ll ans = 1;
        for(int i = 0; i < n-1; i++)  ans *= 2;
        cout << ans << endl;
    }

    return 0;
}