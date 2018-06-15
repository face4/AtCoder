#include<iostream>
using namespace std;

int main(){
    int n, s, t, w;
    cin >> n >> s >> t >> w;

    int diff, ans = 0;
    if(s <= w && w <= t)    ans++;
    
    for(int i = 1; i < n; i++){
        cin >> diff;
        w += diff;
        if(s <= w && w <= t)    ans++;
    }

    cout << ans << endl;
    return 0;
}