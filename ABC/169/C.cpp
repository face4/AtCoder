#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    ll a;
    string s;
    cin >> a >> s;
    int cnt = 0;
    int b = 0;
    bool f = false;
    for(char c : s){
        if(c == '.'){
            f = true;
            continue;
        }
        if(f)   cnt++;
        b = b*10+(c-'0');
    }
    a *= b;
    while(cnt--)    a /= 10;
    cout << a << endl;
    return 0;
}