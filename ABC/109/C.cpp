#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, start, x;
    cin >> n >> start >> x;
    int ans = abs(start-x);

    for(int i = 1; i < n; i++){
        cin >> x;
        ans = gcd(ans, abs(start-x));
    }

    cout << ans << endl;
    
    return 0;
}