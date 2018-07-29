#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    cout << s.length()/2 - count(s.begin(), s.end(), 'p') << endl;
    return 0;
}