#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;

    int n = s.length();

    ll ans = 0;
    for(int i = 0; i < 1<<(n-1); i++){
        ll accum = 0, tmp = s[0]-'0';
        for(int j = 1; j < n; j++){
            if(i & 1<<(j-1)){
                accum += tmp;
                tmp = s[j]-'0';
            }else{
                tmp *= 10ll;
                tmp += s[j]-'0';
            }
        }
        accum += tmp;
        ans += accum;
    }

    cout << ans << endl;

    return 0;
}