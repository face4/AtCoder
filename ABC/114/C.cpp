#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int n;
set<string> se;

bool check(string s){
    int ret = 0;
    for(char c : s){
        if(c == '3')    ret |= 1;
        if(c == '5')    ret |= 2;
        if(c == '7')    ret |= 4;
    }
    return ret == 7;
}

void dfs(string s){
    if(se.count(s)) return;
    if(stoi(s) > n) return;
    if(check(s) && stoi(s) <= n){
        se.insert(s);
    }
    if(s.length() == 9) return;
    dfs(s+"3");
    dfs(s+"5");
    dfs(s+"7");
}

int main(){
    cin >> n;
    
    dfs("3");
    dfs("5");
    dfs("7");

    cout << se.size() << endl;

    return 0;
}