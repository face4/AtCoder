#include<iostream>
using namespace std;

int main(){
    string s[3];
    cin >> s[0] >> s[1] >> s[2];

    int turn = 0;
    int next = 0;
    
    while(1){
        if(s[turn].length()==0) break;
        next = s[turn][0]-'a';
        s[turn] = s[turn].substr(1);
        turn = next;
    }

    cout << (char)('A'+turn) << endl;
    return 0;
}