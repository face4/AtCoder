#include<iostream>
using namespace std;

int main(){
    int cnt = 0;
    string s;
    for(int i = 0; i < 12; i++){
        cin >> s;
        if(s.find("r") != string::npos) cnt++;
    }
    cout << cnt << endl;
    return 0;
}