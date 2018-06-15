#include<iostream>
using namespace std;

int main(){
    int n, a, b, d, pos = 0;
    cin >> n >> a >> b;

    string s;
    for(int i = 0; i < n; i++){
        cin >> s >> d;
        d = max(d, a);
        d = min(d, b);
        if(s[0]=='E')   pos += d;
        if(s[0]=='W')   pos -= d;
    }

    if(pos < 0)         cout << "West " << -pos << endl;
    else if(pos > 0)    cout << "East " << pos << endl;
    else                cout << 0 << endl;

    return 0;
}