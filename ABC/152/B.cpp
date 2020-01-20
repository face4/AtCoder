#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    string s = "", t = "";
    for(int i = 0; i < b; i++)  s += to_string(a);
    for(int i = 0; i < a; i++)  t += to_string(b);
    cout << min(s,t) << endl;
    return 0;
}