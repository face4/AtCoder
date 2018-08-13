#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = n/10 * 100;
    
    if(n % 10 > 6)  ans += 100;
    else            ans += 15 * (n%10);

    cout << ans << endl;

}