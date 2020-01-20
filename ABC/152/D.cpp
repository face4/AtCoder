#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int memo[10][10] = {};
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int ma = to_string(i)[0]-'0';
        int mi = i%10;
        memo[ma][mi]++;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int ma = to_string(i)[0]-'0';
        int mi = i%10;
        ans += memo[mi][ma];
    }
    cout << ans << endl;
    return 0;
}