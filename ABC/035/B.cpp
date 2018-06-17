#include<iostream>
using namespace std;

int main(){
    string s;
    int t;
    cin >> s >> t;

    int x = 0, y = 0, more = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='L')   x--;
        if(s[i]=='R')   x++;
        if(s[i]=='U')   y++;
        if(s[i]=='D')   y--;
        if(s[i]=='?')   more++;
    }

    if(t == 1){
        cout << abs(x)+abs(y)+more << endl;
    }else{
        if(more < abs(x)+abs(y)){
            cout << abs(x)+abs(y)-more << endl;
        }else{
            cout << (more-abs(x)-abs(y))%2 << endl;
        }
    }

    return 0;
}