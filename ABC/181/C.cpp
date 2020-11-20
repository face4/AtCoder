#include<iostream>
using namespace std;

int gcd(int a, int b){
    return b==0 ? a : gcd(b, a%b);
}

int main(){
    int n;
    cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            for(int k = 0; k < n; k++){
                if(i == k || j == k)    continue;
                int a = x[j]-x[i], b = y[j]-y[i];
                int c = x[k]-x[j], d = y[k]-y[j];
                int ga = gcd(abs(a), abs(b)); a /= ga, b /= ga;
                int gc = gcd(abs(c), abs(d)); c /= gc, d /= gc;
                if(a == c && b == d){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}