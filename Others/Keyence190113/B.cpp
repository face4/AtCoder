#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            string a = s.substr(0, i);
            string b = s.substr(j);
            string t = a+b;
            if(t == "keyence"){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}