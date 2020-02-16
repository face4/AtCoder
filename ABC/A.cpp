#include<iostream>
using namespace std;

int main(){
    string s, t;
    int a, b;
    cin >> s >> t >> a >> b;
    string u;
    cin >> u;
    if(s==u)    a--;
    else        b--;
    cout << a << " " << b << endl;
    return 0;
}
