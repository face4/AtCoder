#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int m = 0;
    int pro = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'I')         pro++;
        else if(s[i] == 'D')    pro--;
        m = max(pro, m);
    }
    
    cout << m << endl;

    return 0;
}