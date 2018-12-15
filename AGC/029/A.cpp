#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;

    ll ans = 0;
    int b = 0;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'B') b++;
        else            ans += b;
    }

    cout << ans << endl;
    
    return 0;
}