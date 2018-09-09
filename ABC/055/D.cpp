#include<iostream>
using namespace std;

bool check(string s, string t){
    int n = s.length();

    for(int i = 0; i < n; i++){
        if(s[i] == 'o'){
            if(t[i] == 'S' && t[(i+n-1)%n] != t[(i+1)%n])   return false;
            if(t[i] == 'W' && t[(i+n-1)%n] == t[(i+1)%n])   return false;
        }
        if(s[i] == 'x'){
            if(t[i] == 'S' && t[(i+n-1)%n] == t[(i+1)%n])   return false;
            if(t[i] == 'W' && t[(i+n-1)%n] != t[(i+1)%n])   return false;
        }
    }

    return true;
}

int main(){
    int n;
    string s;

    cin >> n >> s;

    string ans = "-1";

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            string tmp = "";
            if(i == 0)  tmp.push_back('S');
            else        tmp.push_back('W');
            if(j == 0)  tmp.push_back('S');
            else        tmp.push_back('W');
            for(int k = 1; k < n-1; k++){
                if(tmp[k] == 'S'){
                    if(s[k] == 'o')   tmp.push_back(tmp[k-1]);
                    else              tmp.push_back((tmp[k-1] == 'S' ? 'W' : 'S'));
                }else if(tmp[k] == 'W'){
                    if(s[k] == 'o')   tmp.push_back((tmp[k-1] == 'S' ? 'W' : 'S'));
                    else              tmp.push_back(tmp[k-1]);
                }
            }

            if(check(s, tmp)){
                ans = tmp;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}