#include<iostream>
using namespace std;

int main(){
    int m, n, N;
    cin >> m >> n >> N;

    int ans = N;
    int res = N;

    while(res >= m){
        ans += res/m*n;
        res = res/m*n + res%m;
    }

    cout << ans << endl;
    return 0;
}