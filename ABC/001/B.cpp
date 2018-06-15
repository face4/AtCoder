#include<iostream>
using namespace std;

int main(){
    int m;
    string s = "";
    cin >> m;
    if(m < 100){
        s = "00";
    }else if(m <= 5000){
        m /= 100;
        if(m < 10)  s = "0";
        s.append(to_string(m));
    }else if(6000 <= m && m <= 30000){
        m = m/1000 + 50;
        s = to_string(m);
    }else if(35000 <= m && m <= 70000){
        m = (m/1000 - 30) / 5 + 80;
        s = to_string(m);
    }else if(70000 < m){
        s = "89";
    }
    
    cout << s << endl;
    return 0;
}