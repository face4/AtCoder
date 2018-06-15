#include<iostream>
using namespace std;

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << 
    (char)('A' + s1[0] - 'a') << 
    (char)('A' + s2[0] - 'a') << 
    (char)('A' + s3[0] - 'a') << endl;

    return 0;
}