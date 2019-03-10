#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int a, b, k;
    cin >> a >> b >> k;
    int g = gcd(a,b);
    int cnt = 0;
    for(int i = g;; i--){
        if(g%i == 0){
            cnt++;
            if(cnt == k){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}