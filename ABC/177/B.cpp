#include<iostream>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int slen = s.length(), tlen = t.length();
    int ret = 1<<30;
    for(int i = 0; i+tlen <= slen; i++){
        int tmp = 0;
        for(int j = 0; j < tlen; j++)   tmp += s[i+j] != t[j];
        ret = min(ret, tmp);
    }
    cout << ret << endl;
    return 0;
}