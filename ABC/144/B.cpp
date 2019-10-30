#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool ok = false;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            ok |= (i*j == n);
        }
    }
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}