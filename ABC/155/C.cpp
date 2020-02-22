#include<iostream>
#include<map>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    map<string,int> m;
    set<string> ret;
    for(int i = 0; i < n; i++){
        cin >> s;
        m[s]++;
    }
    int x = 0;
    for(auto p : m)   x = max(x, p.second);
    for(auto p : m)   if(x==p.second) ret.insert(p.first);
    for(string t : ret) cout << t << endl;
    return 0;
}
