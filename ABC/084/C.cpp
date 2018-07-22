#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int c[n], s[n], f[n];
    c[n-1] = s[n-1] = f[n-1] = 0;
    for(int i = 0; i < n-1; i++)  cin >> c[i] >> s[i] >> f[i];

    for(int i = 0; i < n-1; i++){
        int ans = 0;
        for(int j = i; j < n-1; j++){
            if(ans <= s[j])  ans = s[j];
            else            ans = (ans-s[j]+f[j]-1)/f[j]*f[j] + s[j];
            ans += c[j];
        }
        cout << ans << endl;
    }

    cout << 0 << endl;

    return 0;
}