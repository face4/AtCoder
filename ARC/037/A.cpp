#include<iostream>
using namespace std;

int main(){
    int n, m, ans = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> m;
        ans += max(80-m, 0);
    }

    cout << ans << endl;
    return 0;
}