#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;

    ll L[n+1];
    L[0] = 2;
    L[1] = 1;
    for(int i = 2; i <= n; i++){
        L[i] = L[i-1]+L[i-2];
    }

    cout << L[n] << endl;
    return 0;
}