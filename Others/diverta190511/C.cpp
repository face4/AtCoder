#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int ans = 0, a = 0, b = 0, ab = 0;
    for(int i = 0; i < n; i++){
        b += s[i][0]=='B';
        a += s[i][s[i].length()-1]=='A';
        ab += s[i][0]=='B'&&s[i][s[i].length()-1]=='A';
        for(int j = 0; j+1 < s[i].length(); j++){
            if(s[i][j]=='A' && s[i][j+1]=='B')  ans++;
        }
    }
    if(ab > 1){
        ans += ab-1, a -= ab, b -= ab;
        if(b)   ans++, b--;
        if(a)   ans++, a--;
    }else if(ab == 1){
        a--, b--;
        if(b)   ans++, b--;
        if(a)   ans++, a--;
    }
    ans += min(a, b);
    cout << ans << endl;
    return 0;
}