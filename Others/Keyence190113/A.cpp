#include<iostream>
using namespace std;

int main(){
    bool b[10] = {};
    int p;
    for(int i = 0; i < 4; i++){
        cin >> p;
        b[p] = true;
    }
    if(b[1] && b[9] && b[7] && b[4])    cout << "YES" << endl;
    else                                cout << "NO" << endl;
    
    return 0;
}