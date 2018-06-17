#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n, q, l, r, t;
    cin >> n >> q;
    
    int a[n] = {};
    for(int i = 0; i < q; i++){
        cin >> l >> r >> t;
        for(int i = l-1; i < r; i++)    a[i] = t;
    }

    for(int i : a)  cout << i << endl;

    return 0;
}