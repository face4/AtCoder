#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    char c;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == 'Y'){
            cout << "Four" << endl;
            return 0;
        }
    }

    cout << "Three" << endl;
    return 0;
}