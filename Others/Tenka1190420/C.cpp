#include<iostream>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int b = 0, w = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.') w++;
        else            b++;
    }
    if(w == 0 || b == 0){
        cout << 0 << endl;
        return 0;
    }
    int ans = min(b,w), wtmp = 0, btmp = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            wtmp++; w--;
        }else{
            btmp++; b--;
        }
        ans = min(ans, btmp+w);
    }
    cout << ans << endl;
    return 0;
}