#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    string s = "";
    while(n > 26){
        s += (char)('a'+(n-1)%26);
        if(n%26 == 0)   n -= 26;
        n /= 26;
    }
    s += (char)('a'+(n-1));
    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}