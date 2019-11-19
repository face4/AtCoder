#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    if(n%2){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n/2+i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}