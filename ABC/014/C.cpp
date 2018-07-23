#include<iostream>
using namespace std;

int from[1000001] = {}, to[1000001] = {};

int main(){
    int n;
    cin >> n;

    int a, b;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        from[a]++;
        to[b]++;
    }

    int ans = 0;
    int tmp = 0;
    for(int i = 0; i <= 1000000; i++){
        tmp += from[i];
        ans = max(ans, tmp);
        tmp -= to[i];
    }

    cout << ans << endl;

    return 0;
}