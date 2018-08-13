#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int b[n];
    for(int i = 0; i < n; i++)  cin >> b[i];

    int x = b[0];
    for(int i = 1; i < n-1; i++)    x ^= b[i];

    if(x == b[n-1]){
        int now = 0;
        cout << now << endl;
        for(int i = 1; i < n; i++){
            now ^= b[i-1];
            cout << now << endl;
        }
    }else{
        cout << -1 << endl;
    }

    return 0;
}