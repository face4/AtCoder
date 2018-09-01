#include<iostream>
using namespace std;

int main(){
    string s, t = "";
    while(cin >> s){
        if(s == "Left")     t += "< ";
        if(s == "Right")    t += "> ";
        if(s == "AtCoder")  t += "A ";
    }
    cout << t.substr(0, t.length()-1) << endl;
    return 0;
}