#include<iostream>
using namespace std;

int main(){
    int d, n;
    cin >> d >> n;

    int ans = 1;
    for(int i = 0; i < d; i++)  ans *= 100;

    if(n == 100) ans *= n+1;
    else         ans *= n;

    cout << ans << endl;
    return 0;
}