#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (to_string(i).length()) % 2;
    }
    cout << ans << endl;
    return 0;
}