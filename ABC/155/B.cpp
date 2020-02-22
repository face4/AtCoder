#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool ok = true;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x%2) continue;
        ok &= x%3==0 || x%5==0;
    }
    cout << (ok ? "APPROVED" : "DENIED") << endl;
    return 0;
}
