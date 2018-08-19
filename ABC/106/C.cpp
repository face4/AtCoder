#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    string s;
    ll k;

    cin >> s >> k;

    if(k < 100){
        bool judge = true;
        for(int i = 0; i < k; i++)  if(s[i] != '1') judge = false;
        if(judge){
            cout << 1 << endl;
        }else{
            int i;
            for(i = 0; i < s.length(); i++) if(s[i] != '1') break;
            cout << s[i] << endl;
        }
    }else{
        int i;
        for(i = 0; i < s.length(); i++) if(s[i] != '1') break;
        cout << s[i] << endl;
    }
    
    return 0;
}