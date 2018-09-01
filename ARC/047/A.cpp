#include<iostream>
using namespace std;

int main(){
    int n, l;
    string s;
    
    cin >> n >> l >> s;

    int tab = 1, ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '+') tab++;
        if(s[i] == '-') tab--;

        if(tab > l){
            ans++;
            tab = 1;
        }
    }

    cout << ans << endl;

    return 0;
}