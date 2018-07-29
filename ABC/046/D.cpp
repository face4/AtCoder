#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    int g = 0, p = 0, win = 0, lose = 0;
    for(int i = 0; i < s.length(); i++){
        if(g == p){
            g++;
            if(s[i] == 'p') lose++;
        }else if(s[i] == 'g'){
            p++;
            win++;
        }else if(s[i] == 'p'){
            p++; // パーを消費してあいこにする.
        }
    }

    cout << win-lose << endl;

    return 0;
}