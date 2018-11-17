#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int tmp = n;
    double ans = -n * log10(m);
    int r;

    for(int i = 0; i < m; i++){
        cin >> r;
        for(int i = 1; i <= r; i++){
            ans += log10(tmp-i+1);
            ans -= log10(i);
        }
        tmp -= r;
    }

    ans *= -1;

    cout << (int)ceil(ans) << endl;

    return 0;
}