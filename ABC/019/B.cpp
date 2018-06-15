#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;

    char c = s[0];
    int cnt = 1;
    
    for(int i = 1; i < s.length(); i++){
        if(c != s[i]){
            cout << c << cnt;
            c = s[i];
            cnt = 1;
        }else{
            cnt++;
        }
    }

    cout << c << cnt << endl;
    return 0;
}