#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll l, r;
    cin >> l >> r;

    vector<bool> v(2019, 0);
    while(l <= r){
        if(v[l%2019])    break;
        v[l%2019] = true;
        l++;
    }

    int ans = 1<<30;
    for(int i = 0; i < 2019; i++){
        for(int j = i+1; j < 2019; j++){
            if(v[i] && v[j])    ans = min(ans, (i*j)%2019);
        }
    }

    cout << ans << endl;

    return 0;
}