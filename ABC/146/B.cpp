#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        cout << (char)((s[i]-'A'+n)%26+'A');
    }
    cout << endl;
    return 0;
}