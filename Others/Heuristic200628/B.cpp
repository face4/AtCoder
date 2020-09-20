#include<iostream>
using namespace std;

typedef long long ll;

int main(){
    int d;
    cin >> d;
    int c[26];
    for(int i = 0; i < 26; i++) cin >> c[i];
    int s[d][26];
    for(int i = 0; i < d; i++){
        for(int j = 0; j < 26; j++){
            cin >> s[i][j];
        }
    }
    int last[26] = {};
    ll sat = 0;
    for(int i = 1; i <= d; i++){
        int t;
        cin >> t;
        sat += s[i-1][t-1];
        last[t-1] = i;
        ll dec = 0;
        for(int j = 0; j < 26; j++) dec += (ll)c[j]*(i-last[j]);
        sat -= dec;
        cout << sat << endl;
    }
    return 0;
}