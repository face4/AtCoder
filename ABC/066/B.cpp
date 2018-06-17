#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    if(s.length()%2 == 0)   s = s.substr(0, s.length()-2);
    else                    s = s.substr(0, s.length()-1);

    while(1){
        int half = s.length()/2;
        if(s.substr(0,half) == s.substr(half,half)){
            break;
        }
        s = s.substr(0, half*2-2);
    }

    cout << s.length() << endl;
    return 0;
}