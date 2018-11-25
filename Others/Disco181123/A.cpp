#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 1;
    while(n-- > 0)  ans *= 4;
    cout << ans << endl;
    return 0;
}