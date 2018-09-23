#include<iostream>
#include<numeric>
using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int husa[n+1];
    for(int i = 1; i <= n; i++) husa[i] = b;

    int l, r;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        for(; l <= r; l++)  husa[l] = a;
    }

    cout << accumulate(husa+1, husa+n+1, 0) << endl;

    return 0;
}