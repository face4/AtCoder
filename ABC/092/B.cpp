#include<iostream>
using namespace std;

int main(){
    int n, d, x;
    cin >> n >> d >> x;

    int choco = x;
    for(int i = 0; i < n; i++){
        cin >> x;
        choco += 1+(d-1)/x;
    }
    
    cout << choco << endl;
    return 0;
}