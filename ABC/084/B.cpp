#include<iostream>
using namespace std;

int main(){
    int a, b;
    string s;
    cin >> a >> b >> s;

    bool judge = true;
    for(int i = 0; i < a+b+1; i++){
        if(i == a && s[i] != '-')                   judge = false;
        if(i != a && (s[i] < '0' || '9' < s[i]))    judge = false;
    }

    if(judge)   cout << "Yes" << endl;
    else        cout << "No" << endl;
    
    return 0;
}