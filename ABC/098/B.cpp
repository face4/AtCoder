#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int res = 0;
    for(int i = 1; i < n-1; i++){
        string t = s.substr(0,i);
        string u = s.substr(i);
        bool first[26] = {};
        bool second[26] = {};

        for(int j = 0; j < i; j++){
            first[t[j]-'a'] = true;
        }

        for(int j = 0; j < n-i; j++){
            second[u[j]-'a'] = true;
        }

        int ans = 0;
        for(int j = 0; j < 26; j++){
            if(first[j] && second[j]){
                ans++;
            }   
        } 

        res = max(res, ans);
    }

    cout << res << endl;
    return 0;
}