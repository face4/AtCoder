#include<iostream>
using namespace std;

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;

    int len;
    for(len = 0; len < n; len++){
        int overlap;
        for(overlap = 0; overlap < n-len; overlap++){
            if(s[len+overlap] != t[overlap])    break;
        }

        if(overlap == n-len)    break;
    }

    cout << n+len << endl;

    return 0;
}