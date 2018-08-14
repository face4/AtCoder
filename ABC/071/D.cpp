#include<iostream>
using namespace std;

typedef long long ll;
ll mod = 1000000007;

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;

    ll ans;
    int index;
    if(s[0] == t[0]){
        index = 1;
        ans = 3;
    }else{
        index = 2;
        ans = 6;
    }

    for(; index < n; index++){
        if(s[index] == t[index]){
            if(s[index-1] == t[index-1])    ans *= 2;
        }else{
            if(s[index-1] == t[index-1])    ans *= 2;
            else                            ans *= 3;
            index++;
        }

        ans %= mod;
    }

    cout << ans << endl;

    return 0;
}