#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    for(char c : s){
        if(c == '7'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}