#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int ans = 900 + a%100 - b;
    ans = max(ans, a + 90 - ((a/10)%10)*10 - b);
    ans = max(ans, a + 9 - a%10 - b);
    ans = max(ans, a - (100 + b%100));
    ans = max(ans, a - (b - ((b/10)%10)*10));
    ans = max(ans, a - (b - b%10));

    cout << ans << endl;
}