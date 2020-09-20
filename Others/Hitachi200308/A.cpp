#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    if(n%2){
        cout << "No" << endl;
        return 0;
    }
    bool y = true;
    for(int i = 0; i < n; i+=2){
        y &= s.substr(i,2)=="hi";
    }
    cout << (y ? "Yes" : "No") << endl;
    return 0;
}