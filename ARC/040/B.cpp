#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, r;
    string s;
    cin >> n >> r >> s;

    int last;
    for(last = n-1; last >= 0; last--)    if(s[last] == '.')  break;

    int ans = 0, pos = 0;
    while(count(s.begin(), s.end(), 'o') != n){
        if(last <= pos + r - 1){
            ans++;
            break;
        }

        if(s[pos] == '.'){
            for(int i = 0; i < r && i + pos < n; i++)  s[i+pos] = 'o';
        }else{
            pos++;
        }

        ans++;
    }

    cout << ans << endl;
    
    return 0;
}