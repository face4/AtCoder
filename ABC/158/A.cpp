#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(int i = 1; i < 3; i++){
        if(s[i] != s[i-1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}