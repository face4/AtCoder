#include<iostream>
using namespace std;

int main(){
    int l, h, n, a;
    cin >> l >> h >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        if(a > h)       cout << -1 << endl;
        else            cout << abs(min(0, a-l)) << endl;
    }

    return 0;
}