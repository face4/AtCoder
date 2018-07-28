#include<iostream>
using namespace std;

int just(string x){
    int ret = 0;
    for(int i = 0; i < x.length(); i++){
        ret += x[i] - '0';
    }
    return ret;
}

int main(){
    string s;
    cin >> s;
    cout << max(just(s), (s[0]-'0'-1) + 9*(int)((s.length()-1))) << endl;
    return 0;
}