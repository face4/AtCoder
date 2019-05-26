#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    string a = s.substr(0,2), b = s.substr(2);
    int y = stoi(a), m = stoi(b);
    bool c = y <= 12 && y != 0;
    bool d = m <= 12 && m != 0;
    if(c&&d)    cout << "AMBIGUOUS" << endl;
    else if(c)  cout << "MMYY" << endl;
    else if(d)  cout << "YYMM" << endl;
    else        cout << "NA" << endl;
    return 0;
}