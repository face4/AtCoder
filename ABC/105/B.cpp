#include<iostream>
using namespace std;

int main(){
    bool b[110] = {};
    b[0] = true;
    for(int i = 0; i < 101; i++){
        if(b[i])    b[i+4] = b[i+7] = true;
    }

    int n;
    cin >> n;

    if(b[n])    cout << "Yes" << endl;
    else        cout << "No" << endl;
    
    return 0;
}