#include<iostream>
using namespace std;

int main(){
    string s;
    int w;
    cin >> s >> w;

    for(int i = 0; i < s.length(); i += w){
        cout << s[i];
    }
    cout << endl;
    
    return 0;
}