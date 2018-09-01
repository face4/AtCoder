#include<iostream>
using namespace std;

int main(){
    string s;
    int a, b, c, d;

    cin >> s >> a >> b >> c >> d;

    s.insert(s.begin()+a, '\"');
    s.insert(s.begin()+b+1, '\"');
    s.insert(s.begin()+c+2, '\"');
    s.insert(s.begin()+d+3, '\"');

    cout << s << endl;

    return 0;
}