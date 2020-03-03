#include<iostream>
#include<set>
using namespace std;

int main(){
    int n, q;
    string s;
    cin >> n >> s >> q;
    set<int> t[26];
    for(int i = 0; i < n; i++)  t[s[i]-'a'].insert(i+1);
    for(int i = 0; i < 26; i++) t[i].insert(n+1);
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int i;
            char c;
            cin >> i >> c;
            i--;
            t[s[i]-'a'].erase(i+1);
            s[i] = c;
            t[s[i]-'a'].insert(i+1);
        }else if(op == 2){
            int l, r;
            cin >> l >> r;
            int ans = 0;
            for(int i = 0; i < 26; i++) ans += *(t[i].lower_bound(l)) <= r;
            cout << ans << endl;
        }
    }
    return 0;
}