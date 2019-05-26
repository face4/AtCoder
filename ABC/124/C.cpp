#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    string t = "01";
    for(int i = 0; i < s.length(); i++){
        if(t[i%2] != s[i])  a++;
        if(t[(i+1)%2] != s[i])  b++;
    }
    cout << min(a, b) << endl;
    return 0;
}