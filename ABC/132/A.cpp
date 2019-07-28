#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool j = s[0] == s[1] && s[1] != s[2] && s[2]==s[3];
    cout << (j ? "Yes" : "No") << endl;
    return 0;
}