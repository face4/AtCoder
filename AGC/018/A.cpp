#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(){
    int n, k;
    cin >> n >> k;

    int g, a, m;
    cin >> g;
    m = g;
    
    for(int i = 1; i < n; i++){
        cin >> a;
        g = gcd(g, a);
        m = max(m, a);
    }

    if(m >= k && k%g == 0){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}