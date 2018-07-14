#include<iostream>
using namespace std;

// strの接頭辞がpreかどうかを判別する.
bool startsWith(string str, string pre){
    int s = str.length(), p = pre.length();
    if(s < p)   return false;

    int j;
    for(j = 0; j < p; j++){ 
        if(str[j] != pre[j])  break;
    }

    return j == p;
}

int main(){
    string piano = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
    
    string s;
    cin >> s;
    
    int i;
    for(i = 0; i < 12; i++){
        if(startsWith(piano.substr(i), s))    break;
    }

    if(i <= 1){
        cout << "Do" << endl;
    }else if(i <= 3){
        cout << "Re" << endl;
    }else if(i == 4){
        cout << "Mi" << endl;
    }else if(i <= 6){
        cout << "Fa" << endl;
    }else if(i <= 8){
        cout << "So" << endl;
    }else if(i <= 10){
        cout << "La" << endl;
    }else if(i <= 11){
        cout << "Si" << endl;
    }

    return 0;
}