#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    int q;
    cin >> s >> q;
    int f = 0;
    vector<char> v[2];
    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            f = 1-f;
        }else if(op == 2){
            int a;
            char b;
            cin >> a >> b;
            a--;
            v[f^a].push_back(b);
        }
    }
    for(char c : v[1])  s += c;
    reverse(s.begin(), s.end());
    for(char c : v[0])  s += c;
    if(!f)  reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}