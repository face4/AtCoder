#include<iostream>
using namespace std;

bool isLower(char x){
    return 'a' <= x && x <= 'z';
}

int main(){
    string s;
    cin >> s;

    if(s[0] == 'A'){
        bool c = false;
        bool judge = true;
        for(int i = 2; i < s.length()-1; i++){
            if(!c && s[i] == 'C'){
                c = true;
            }else if(isLower(s[i])){
                // do nothing
            }else{
                judge = false;
            }
        }

        if(c && judge && isLower(s[1]) && isLower(s[s.length()-1])) 
            cout << "AC" << endl;
        else
            cout << "WA" << endl;
    }else{
        cout << "WA" << endl;
    }

    return 0;
}