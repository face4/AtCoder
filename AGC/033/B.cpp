#include<iostream>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;
    int r, c;
    cin >> r >> c;
    string s, t;
    cin >> s >> t;
    bool remain = true;
    
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'L')  cnt++;
        if(cnt >= c)    remain = false;
        if(t[i] == 'R' && c-cnt != w)   cnt--;
    }

    cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R')  cnt++;
        if(cnt >= w-c+1) remain = false;
        if(t[i] == 'L' && c+cnt != 1)   cnt--;
    }

    cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'U')  cnt++;
        if(cnt >= r) remain = false;
        if(t[i] == 'D' && r-cnt != h)   cnt--;
    }

    cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'D')  cnt++;
        if(cnt >= h-r+1) remain = false;
        if(t[i] == 'U' && r+cnt != 1)   cnt--;
    }

    cout << (remain ? "YES" : "NO") << endl;
    return 0;
}