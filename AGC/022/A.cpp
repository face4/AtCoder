#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    if(s.length() < 26){
        char x = 'a';
        while(1){
            bool judge = true;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == x)   judge = false;
            }
            if(judge)   break;
            else    x = (char)(x+1);
        }
        cout << s << x << endl;
    }else{
        s = s.substr(0, 26);
        int i;
        for(i = 25; i >= 0; i--){
            if(s[i] == 'z') continue;
            bool judge;
            char next = (char)(s[i]+1);
            while(next <= 'z'){
                judge = true;
                for(int j = i-1; j >= 0; j--){
                    if(next == s[j])    judge = false;
                }

                if(judge){
                    s[i] = next;
                    break;
                }else{
                    next = (char)(1+next);
                }
            }
            if(judge)   break;
        }

        if(i == -1)
            cout << -1 << endl;
        else 
            cout << s.substr(0, i+1);
    }
    return 0;
}