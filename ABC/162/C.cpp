#include<iostream>
#include<numeric>
using namespace std;

typedef long long ll;

int main(){
    int k;
    cin >> k;
    ll ret = 0;
    for(int i = 1; i <= k; i++){
        for(int j = 1; j <= k; j++){
            int g = gcd(i, j);
            for(int x = 1; x <= k; x++){
                ret += gcd(g, x);
            }
        }
    }
    cout << ret << endl;
    return 0;
}