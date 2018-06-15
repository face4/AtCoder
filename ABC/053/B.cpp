#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int apos, zpos;
    
    for(apos = 0; s[apos] != 'A'; apos++);
    for(zpos = s.size()-1; s[zpos] != 'Z'; zpos--);

    cout << zpos-apos+1 << endl;
    return 0;
}