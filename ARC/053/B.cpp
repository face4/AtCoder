#include<iostream>
using namespace std;

int main(){
    char c;
    int cnt[26] = {};
    while(cin >> c) cnt[c-'a']++;
    int odd = 0, pair = 0;
    for(int x : cnt)    odd += x%2, pair += x/2;
    if(odd) cout << 1+pair/odd*2 << endl;
    else    cout << pair*2 << endl;
    return 0;
}