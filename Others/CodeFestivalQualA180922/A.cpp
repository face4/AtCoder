#include<iostream>
using namespace std;

int main(){
    int a, b, c, s;
    cin >> a >> b >> c >> s;
    bool judge = (a+b+c) <= s && s <= (a+b+c+3);
    if(judge)   cout << "Yes" << endl;
    else        cout << "No" << endl;
    return 0;
}