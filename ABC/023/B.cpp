#include<iostream>
using namespace std;

int main(){
    int n, i;
    string s;
    cin >> n >> s;

    string t = "b";
    for(i = 0; t.length() < s.length(); i++){
        if(i%3==0)  t = "a"+t+"c";
        if(i%3==1)  t = "c"+t+"a";
        if(i%3==2)  t = "b"+t+"b";
    }

    if(s == t)  cout << i << endl;
    else        cout << -1 << endl;

    return 0;
}