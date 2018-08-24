#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    
    for(int i = 0; i < s.length(); i++) s[i] = toupper(s[i]);

    int status = 0;
    for(int i = 0; i < s.length(); i++){
        if( (status == 0 && s[i] == 'I') ||
            (status == 1 && s[i] == 'C') ||
            (status == 2 && s[i] == 'T')   )
            status++;
    }

    if(status == 3) cout << "YES" << endl;
    else            cout << "NO" << endl;

    return 0;
}