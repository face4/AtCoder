#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    string res = "";

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '0')                             res += "0";
        else if(s[i] == '1')                        res += "1";
        else if(s[i] == 'B' && res.length() != 0)   res = res.substr(0, res.length()-1); 
    }

    cout << res << endl;
    return 0;
}