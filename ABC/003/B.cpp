#include<iostream>
using namespace std;

bool check(char x){
    return x=='a' || x=='t' || x=='c' || x=='o' || x=='d' || x=='e' || x=='r';
}

int main(){
    string s;
    string t;
    cin >> s >> t;

    for(int i = 0; i < s.length(); i++){
        if(s[i]==t[i]){
            // ok.
        }else if(s[i]=='@' && check(t[i])){
            // ok.
        }else if(check(s[i]) && t[i]=='@'){
            // ok.
        }else if(s[i]=='@' && t[i]=='@'){
            // ok.
        }else{
            cout << "You will lose" << endl;
            return 0;
        }
    }

    cout << "You can win" << endl;
    return 0;
}